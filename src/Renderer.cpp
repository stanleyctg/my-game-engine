#include "Renderer.h"
#include <iostream>

Renderer::Renderer(ECS& ecs) : ecs(ecs) {};

Renderer::~Renderer() {
    if (sdlRenderer) {
        SDL_DestroyRenderer(sdlRenderer);
        sdlRenderer = nullptr;
    }
}

void Renderer::init(SDL_Window* window) {
    sdlRenderer= SDL_CreateRenderer(window, -1, 0);
    if (sdlRenderer == nullptr) {
        std::cout << "Error with creating renderer: " << SDL_GetError() << '\n';
    }
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(sdlRenderer, 30, 30, 30, 255);
    SDL_RenderClear(sdlRenderer);
}

void Renderer::draw() {
    auto& renderables = ecs.getRenderables();
    auto& positions = ecs.getPositions();

    for (auto& [id, renderable] : renderables) {
        SDL_Rect rect;
        if (positions.count(id)) {
            auto& position = positions[id];
            rect.w = renderable.width;
            rect.h = renderable.height;
            rect.x = position.x;
            rect.y = position.y;
        };
        SDL_SetRenderDrawColor( sdlRenderer, 0, 0, 255, 255 );
        SDL_RenderDrawRect(sdlRenderer, &rect);
    }
}

void Renderer::present() {
    SDL_RenderPresent(sdlRenderer);
}