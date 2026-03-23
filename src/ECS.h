#pragma once
#include <unordered_map>

using EntityID = unsigned int;

struct PositionComponent {
    float x, y;
};

struct VelocityComponent {
    float dx, dy;
};

struct RenderComponent {
    float width, height;
};

class ECS {
    public:
        EntityID createEntity();
        void destroyEntity(EntityID id);
        void addPosition(EntityID id, float x, float y);
        void addVelocity(EntityID id, float x, float y);
        void addRender(EntityID id, float w, float h);
        std::unordered_map<EntityID, PositionComponent> getPositions();
        std::unordered_map<EntityID, RenderComponent> getRenderables();
        void update();
        void update_right();
        void update_left();

    private:
        EntityID nextID = 0;
        std::unordered_map<EntityID, PositionComponent> positions;
        std::unordered_map<EntityID, VelocityComponent> velocities;
        std::unordered_map<EntityID, RenderComponent> renders;
};