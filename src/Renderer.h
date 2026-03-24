#pragma once

#include <SDL.h>
#include <ECS.h>

class Renderer {
    public:
        Renderer(ECS& ecs);
        void init(SDL_Window* window);
        void clear();
        void draw();
        void present();
    private:
        SDL_Renderer* sdlRenderer = nullptr;
        ECS& ecs;
};