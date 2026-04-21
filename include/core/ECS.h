#pragma once
#include <unordered_map>
#include <vector>
#include "constants.h"

using EntityID = unsigned int;

class ECS {
    public:
        EntityID createEntity();
        void destroyEntity(EntityID id);
        void addPosition(EntityID id, float x, float y);
        void addVelocity(EntityID id, float x, float y);
        void addRender(EntityID id, float w, float h);
        std::unordered_map<EntityID, PositionComponent>& getPositions();
        std::unordered_map<EntityID, RenderComponent>& getRenderables();
        std::unordered_map<EntityID, VelocityComponent>& getVelocities();
        void update();
        void update_right();
        void update_left();

    private:
        EntityID nextID = 0;
        std::unordered_map<EntityID, PositionComponent> positions;
        std::unordered_map<EntityID, VelocityComponent> velocities;
        std::unordered_map<EntityID, RenderComponent> renders;
        std::vector<EntityID> entities;
};