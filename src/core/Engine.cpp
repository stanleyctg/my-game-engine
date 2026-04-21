#include "Engine.h"
#include <iostream>
#include "constants.h"

Engine::Engine() : window("Game Engine", WINDOW_WIDTH, WINDOW_HEIGHT), physics(ecs), renderer(ecs, window) {}

void Engine::init() {
    renderer.init(window);

    // Create a renderer obj with engine
    EntityID e1 = ecs.createEntity();
    ecs.addPosition(e1, 0.0f, 0.0f);
    ecs.addVelocity(e1, 1.0f, 0.5f);
    ecs.addRender(e1,20,20);

    EntityID e2 = ecs.createEntity();
    ecs.addPosition(e2, 100.0f, 50.0f);
    ecs.addVelocity(e2, 2.0f, 0.5f);
    ecs.addRender(e2,20,20);
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
    if (input.isPressed(SDLK_d) || input.isHeld(SDLK_d)) {
        ecs.update_right();
    }
    if (input.isPressed(SDLK_a) || input.isHeld(SDLK_a)) {
        ecs.update_left();
    } 
    physics.applyGravity();
    ecs.update();  
    physics.applyCollision();  
}

void Engine::render() {
    renderer.clear();
    renderer.draw();
    renderer.present();
}