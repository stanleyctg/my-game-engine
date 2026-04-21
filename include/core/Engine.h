#pragma once
#include <SDL.h>
#include "ECS.h"
#include "Input.h"
#include "Renderer.h"
#include "Physics.h"
#include "Window.h"

class Engine {
    public:
        Engine();
        void init();
        void run();
        void shutdown();
    private:
        void processInput();
        void update();
        void render();
        SDL_Surface* screenSurface = nullptr;
        bool is_running = false;
        ECS ecs;
        Input input;
        Renderer renderer;
        Physics physics;
        Window window;
};