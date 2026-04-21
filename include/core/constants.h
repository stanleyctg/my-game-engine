#pragma once

struct PositionComponent {
    float x, y;
};

struct VelocityComponent {
    float dx, dy;
};

struct RenderComponent {
    float width, height;
};

const int TARGET_FPS = 60;
const int TARGET_FRAME_MS = 1000 / TARGET_FPS;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;