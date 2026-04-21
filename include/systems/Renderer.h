#pragma once

#include <SDL.h>
#include <ECS.h>
#include "Window.h"

class Renderer {
    public:
        Renderer(ECS& ecs, Window& window);
        ~Renderer();
        void init(Window& window);
        void clear();
        void draw();
        void present();
    private:
        SDL_Renderer* sdlRenderer = nullptr;
        ECS& ecs;
        Window& window;
};