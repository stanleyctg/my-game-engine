#include "Renderer.h"
#include <iostream>

Renderer::Renderer(ECS& ecs, Window& window) : ecs(ecs), window(window) {}

Renderer::~Renderer() {
    if (sdlRenderer) {
        SDL_DestroyRenderer(sdlRenderer);
        sdlRenderer = nullptr;
    }
}

void Renderer::init(Window& window) {
    sdlRenderer= SDL_CreateRenderer(window.getSDLWindow(), -1, 0);
    if (sdlRenderer == nullptr) {
        std::cout << "Error with creating renderer: " << SDL_GetError() << '\n';
    }
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(sdlRenderer, 30, 30, 30, 255);
    SDL_RenderClear(sdlRenderer);
}

void Renderer::drawCircle(int cx, int cy, int radius) {
    // Placeholder for future circle drawing implementation
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        SDL_RenderDrawLine(sdlRenderer, cx - x, cy + y, cx + x, cy + y);
        SDL_RenderDrawLine(sdlRenderer, cx - x, cy - y, cx + x, cy - y);
        SDL_RenderDrawLine(sdlRenderer, cx - y, cy + x, cx + y, cy + x);
        SDL_RenderDrawLine(sdlRenderer, cx - y, cy - x, cx + y, cy - x);

        y++;
        if (err <= 0) err += 2 * y + 1;
        if (err > 0) { x--; err -= 2 * x + 1; }
    }
}

void Renderer::draw() {
    auto& renderables = ecs.getRenderables();
    auto& positions = ecs.getPositions();

    for (auto& [id, renderable] : renderables) {
        if (positions.count(id)) {
            auto& position = positions[id];

            SDL_SetRenderDrawColor(sdlRenderer, 
                renderable.color.r, 
                renderable.color.g, 
                renderable.color.b, 
                renderable.color.a
            );

            if (renderable.shape == Shape::Circle) {
                // Wrap in rect for now, will implement actual circle rendering later
                int radius = renderable.width / 2; // Assuming width is diameter for circles
                int cx = position.x + radius;
                int cy = position.y + radius;
                drawCircle(cx, cy, radius);
            } else {
                SDL_Rect rect = {
                    (int)position.x,
                    (int)position.y,
                    (int)renderable.width,
                    (int)renderable.height
                };
                SDL_RenderFillRect(sdlRenderer, &rect);
            }
        }
    }
}

void Renderer::present() {
    SDL_RenderPresent(sdlRenderer);
}