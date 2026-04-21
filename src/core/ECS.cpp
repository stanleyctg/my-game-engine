#include "ECS.h"
#include <iostream>

EntityID ECS::createEntity(EntityConfig config) {
    EntityID id = nextID++;
    positions[id] = config.position;
    velocities[id] = config.velocity;
    renders[id] = config.render;
    return id;
}

void ECS::destroyEntity(EntityID id) {
    positions.erase(id);
    velocities.erase(id);
    renders.erase(id);
}

void ECS::addPosition(EntityID id, float x, float y) {
    positions[id] = {x, y};
}

void ECS::addVelocity(EntityID id, float dx, float dy) {
    velocities[id] = {dx, dy};
}

void ECS::addRender(EntityID id, float w, float h, SDL_Color color, Shape shape) {
    renders[id] = {w, h, color, shape};
}

void ECS::applyGravity(EntityID id, bool apply) {
    physicsFlags[id].applyGravity = apply;
}

void ECS::applyCollision(EntityID id, bool apply) {
    physicsFlags[id].applyCollision = apply;
}

void ECS::isStatic(EntityID id, bool apply) {
    physicsFlags[id].isStatic = apply;
}

std::unordered_map<EntityID, PositionComponent>& ECS::getPositions() {
    return positions;
}

std::unordered_map<EntityID, RenderComponent>& ECS::getRenderables() {
    return renders;
}

std::unordered_map<EntityID, VelocityComponent>& ECS::getVelocities() {
    return velocities;
}

std::unordered_map<EntityID, FlagPhysics>& ECS::getPhysicsFlags() {
    return physicsFlags;
}

void ECS::update() {
    for (auto& [id, v] : velocities) {
        if (positions.count(id)) {
            auto& pos = positions.at(id);

            if (physicsFlags[id].isStatic) {
                if (physicsFlags[id].applyGravity) {
                    pos.y += v.dy; // Apply gravity to static objects if enabled
                }
                continue;
            }
            pos.x += v.dx;
            pos.y += v.dy;
        }
    }
}

// void ECS::update_right() {
//     for (auto& [id, v] : velocities) {
//         if (positions.count(id)) {
//             auto& pos = positions.at(id);
//             pos.x += v.dx;
//         }
//     }
// }

// void ECS::update_left() {
//     for (auto& [id, v] : velocities) {
//         if (positions.count(id)) {
//             auto& pos = positions.at(id);
//             pos.x -= v.dx;
//         }
//     }
// }