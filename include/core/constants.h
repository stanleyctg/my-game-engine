#pragma once
#include <SDL.h>

enum class Shape {
    Rectangle,
    Circle
};

struct PositionComponent {
    float x, y;
};

struct VelocityComponent {
    float dx, dy;
};

struct RenderComponent {
    float width, height;
    SDL_Color color;
    Shape shape;
};

struct EntityConfig {
    PositionComponent position = {0, 0};
    VelocityComponent velocity = {0, 0};
    RenderComponent render = {20, 20, {255, 255, 255, 255}, Shape::Rectangle};
};

const int TARGET_FPS = 60;
const int TARGET_FRAME_MS = 1000 / TARGET_FPS;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;