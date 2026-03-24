#include "Physics.h"
#include <algorithm>
#include "constants.h"

void Physics::applyGravity() {
    for (auto& [id, velocity] : velocities) {
        velocity.dy += 0.1f;
    }
}

void Physics::applyCollision() {
    // detect collision()
    // resolve collition()
    checkAndResolveBoundaries();
    detectCollision();
    resolveCollision();

}

bool Physics::checkCollision(EntityID a, EntityID b) {
    // Pure AABB logic and surface touching
    // init the values
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;   
    int botA, botB;

    // calculate the sides of A
    leftA = positions[a].x;
    rightA = positions[a].x + renderables[a].width;
    topA = positions[a].y;
    botA = positions[a].y + renderables[a].height;

    // calculate the sides of B
    leftB = positions[b].x;
    rightB = positions[b].x + renderables[b].width;
    topB = positions[b].y;
    botB = positions[b].y + renderables[b].height;   

    // AABB logic check
    if (botA <= topB) {
        return false;
    }
    if (topA >= botB) {
        return false;
    }
    if (rightA <= leftB) {
        return false;
    }
    if (leftA >= rightB) {
        return false;
    }
    return true;
}

void Physics::detectCollision() {
    // Goes through each entity and identify colliding pairs
    for (auto& [idA,_] : positions) {
        for (auto& [idB,_] : positions) {
            if (idA != idB && idA < idB) {
                if (checkCollision(idA, idB)) {
                    collisionPairsQueue.emplace(idA, idB);
                }
            }
        }
    }
}

void Physics::resolveCollision() {
    // From the queue update their velocity post collision
    while (!collisionPairsQueue.empty()) {
        auto pair = collisionPairsQueue.front();
        collisionPairsQueue.pop();
        auto& velA = velocities[pair.first];
        auto& velB = velocities[pair.second];
        auto& posA = positions[pair.first];
        auto& posB = positions[pair.second];
        auto& renA = renderables[pair.first];
        auto& renB = renderables[pair.second];

        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;   
        int botA, botB;

        // calculate the sides of A
        leftA = positions[pair.first].x;
        rightA = positions[pair.first].x + renderables[pair.first].width;
        topA = positions[pair.first].y;
        botA = positions[pair.first].y + renderables[pair.first].height;

        // calculate the sides of B
        leftB = positions[pair.second].x;
        rightB = positions[pair.second].x + renderables[pair.second].width;
        topB = positions[pair.second].y;
        botB = positions[pair.second].y + renderables[pair.second].height;   

        // calculate the overlap and undo it
        auto overlapX = std::min(rightA, rightB) -  std::max(leftA, leftB);
        auto overlapY = std::min(botA, botB) - std::max(topA, topB);

        if (overlapX < overlapY) {
            if (posA.x < posB.x) {
                posA.x -= overlapX / 2;
                posB.x += overlapX / 2;
            }else {
                posA.x += overlapX / 2;
                posB.x -= overlapX / 2;
            }
        }else {
            if (posA.y < posB.y) {
                posA.y -= overlapY / 2;
                posB.y += overlapY / 2;
            }else {
                posA.y += overlapY / 2;
                posB.y -= overlapY / 2;
            }
        }
    } 
}

void Physics::checkAndResolveBoundaries() {
    for (auto& [id, _] : positions) {
        auto& ren = renderables[id];
        auto& pos = positions[id];
        auto& vel = velocities[id];

        if (pos.y + ren.height >= WINDOW_HEIGHT) {
            pos.y = WINDOW_HEIGHT - ren.height;
            vel.dy = 0;
        }
        if (pos.y <= 0) {
            pos.y = 0;
        }
        if (pos.x + ren.width >= WINDOW_WIDTH) {
            pos.x = WINDOW_WIDTH - ren.width;
        }
        if (pos.x <= 0) {
            pos.x = 0;
        }    
    }
}