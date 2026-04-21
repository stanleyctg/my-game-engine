#include "Engine.h"
#include <iostream>
#include "constants.h"

Engine::Engine() : window("Game Engine", WINDOW_WIDTH, WINDOW_HEIGHT), physics(ecs), renderer(ecs, window) {}

void Engine::init() {
    renderer.init(window);

    // Create a renderer obj with engine
    EntityConfig config1 = {
        .position = {0.0f, 0.0f},
        .render = {50, 20, {255, 255, 255, 255}, Shape::Circle}
    };
    EntityID e1 = ecs.createEntity(config1);

    EntityConfig config2 = {
        .position = {100.0f, 50.0f},
        .velocity = {2.0f, 10.0f},
        .render = {20, 20, {255, 255, 255, 255}, Shape::Rectangle}
    };
    EntityID e2 = ecs.createEntity(config2);
    ecs.applyGravity(e2, false);
    ecs.applyCollision(e2, false);
    ecs.isStatic(e2, true);
}

void Engine::run() {
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
    }
}

void Engine::shutdown() {
    SDL_Quit();
}

void Engine::processInput() {
    input.update();
    if (input.isPressed(SDLK_ESCAPE)) { is_running = false; }
    if (input.isQuit()) { is_running = false; }
}

void Engine::update() { 
    // if (input.isPressed(SDLK_d) || input.isHeld(SDLK_d)) {
    //     ecs.update_right();
    // }
    // if (input.isPressed(SDLK_a) || input.isHeld(SDLK_a)) {
    //     ecs.update_left();
    // } 
    physics.applyGravity();
    ecs.update();  
    physics.applyCollision();  
}

void Engine::render() {
    renderer.clear();
    renderer.draw();
    renderer.present();
}