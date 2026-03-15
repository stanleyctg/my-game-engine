#include "engine.h"
#include <iostream>

void Engine::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error: " << SDL_GetError() << '\n';
        return;
    }
    window = SDL_CreateWindow(
        "Game Engine",
        200,
        200,
        800,
        600,
        SDL_WINDOW_SHOWN
    );
    if (window == nullptr) {
        std::cout << "Error: " << SDL_GetError() << '\n';
        return;
    }
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(
        screenSurface,
        NULL,
        SDL_MapRGB(screenSurface->format, 0XFF, 0XFF, 0XBB)
    );
    SDL_UpdateWindowSurface(window);
}

void Engine::run() {
    const int TARGET_FPS = 60;
    const int TARGET_FRAME_MS = 1000 / TARGET_FPS;
    is_running = true;
    while (is_running) {
        int frameStart = SDL_GetTicks();
        processInput();
        update();
        render();
        int frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < TARGET_FRAME_MS) {
            SDL_Delay(TARGET_FRAME_MS - frameTime);
        }
        std::cout << "Frame time: " << SDL_GetTicks() - frameStart << "ms\n";
    }
}

void Engine::shutdown() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::processInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) { is_running=false; }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) { is_running=false; }
    }
}

void Engine::update() {}

void Engine::render() {}