#include "ECS.h"
#include <iostream>

EntityID ECS::createEntity() {
    return nextID++;
}

void ECS::destroyEntity(EntityID id) {
    positions.erase(id);
    velocities.erase(id);
}

void ECS::addPosition(EntityID id, float x, float y) {
    positions[id] = {x, y};
}

void ECS::addVelocity(EntityID id, float dx, float dy) {
    velocities[id] = {dx, dy};
}

void ECS::update() {
    for (auto& [id, v] : velocities) {
        if (positions.count(id)) {
            auto& pos = positions.at(id);
            pos.x += v.dx;
            pos.y += v.dy;
            std::cout << "ECS: " << id << "pos: " << pos.x << " " << pos.y << "\n";
        }
    }
}