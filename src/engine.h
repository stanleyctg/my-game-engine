#pragma once
#include <SDL.h>
#include "ECS.h"

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
        SDL_Renderer* renderer = nullptr;
        bool is_running = false;
        ECS ecs;
};