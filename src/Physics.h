#pragma once
#include "ECS.h"
#include <queue>

class Physics {
    public:
        Physics(ECS& ecs) : 
            ecs(ecs), 
            positions(ecs.getPositions()),
            renderables(ecs.getRenderables()),
            velocities(ecs.getVelocities())
        {}
        void applyGravity();
        void applyCollision();
    private:
        ECS& ecs;
        bool checkCollision(EntityID a, EntityID b);
        void detectCollision(); 
        void resolveCollision();
        void checkAndResolveBoundaries();
        std::queue<std::pair<EntityID, EntityID>> collisionPairsQueue;
        std::unordered_map<EntityID, PositionComponent>& positions;
        std::unordered_map<EntityID, RenderComponent>& renderables;
        std::unordered_map<EntityID, VelocityComponent>& velocities;
};