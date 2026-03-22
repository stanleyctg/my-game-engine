#pragma once
#include <SDL.h>
#include "ECS.h"
#include "Input.h"
#include "Renderer.h"

class Engine {
    public:
        void init();
        void run();
        void shutdown();
    private:
        void processInput();
        void update();
        void render();
        SDL_Window* window = nullptr;
        SDL_Surface* screenSurface = nullptr;
        bool is_running = false;
        ECS ecs;
        Input input;
        Renderer renderer;
};