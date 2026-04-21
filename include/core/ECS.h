#pragma once
#include <unordered_map>
#include "constants.h"

using EntityID = unsigned int;

class ECS {
    public:
        EntityID createEntity(EntityConfig config);
        void destroyEntity(EntityID id);
        std::unordered_map<EntityID, PositionComponent>& getPositions();
        std::unordered_map<EntityID, RenderComponent>& getRenderables();
        std::unordered_map<EntityID, VelocityComponent>& getVelocities();
        std::unordered_map<EntityID, FlagPhysics>& getPhysicsFlags();
        void update();
        void applyGravity(EntityID id, bool apply);
        void applyCollision(EntityID id, bool apply);
        void isStatic(EntityID id, bool apply);

    private:
        EntityID nextID = 0;
        std::unordered_map<EntityID, PositionComponent> positions;
        std::unordered_map<EntityID, VelocityComponent> velocities;
        std::unordered_map<EntityID, RenderComponent> renders;
        std::unordered_map<EntityID, FlagPhysics> physicsFlags;
        void addPosition(EntityID id, float x, float y);
        void addVelocity(EntityID id, float x, float y);
        void addRender(EntityID id, float w, float h, SDL_Color color, Shape shape);
};