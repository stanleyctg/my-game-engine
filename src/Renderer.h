#pragma once

#include <SDL.h>
#include <ECS.h>

class Renderer {
    public:
        void init(SDL_Window* window);
        void clear();
        void draw(ECS& ecs);
        void present();
    private:
        SDL_Renderer* sdlRenderer = nullptr;
};