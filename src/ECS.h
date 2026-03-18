#pragma once
#include <unordered_map>

using EntityID = unsigned int;

struct PositionComponent {
    float x, y;
};

struct VelocityComponent {
    float dx, dy;
};

class ECS {
    public:
        EntityID createEntity();
        void destroyEntity(EntityID id);
        void addPosition(EntityID id, float x, float y);
        void addVelocity(EntityID id, float x, float y);
        void update();

    private:
        EntityID nextID = 0;
        std::unordered_map<EntityID, PositionComponent> positions;
        std::unordered_map<EntityID, VelocityComponent> velocities;
};