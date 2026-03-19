#include "Input.h"

void Input::update() {
    SDL_Event e;
    if (currentStates != nullptr) {
        memcpy(previousState, currentStates, SDL_NUM_SCANCODES);
    }
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) { quit=true; }
    }
    currentStates = SDL_GetKeyboardState(NULL);
}

bool Input::isHeld(KeyCode key) {
    SDL_Scancode scanCode;
    scanCode = SDL_GetScancodeFromKey(key);
    if (previousState[scanCode] == 1 && currentStates[scanCode] == 1) {
        return true;
    } return false;
}

bool Input::isPressed(KeyCode key) {
    SDL_Scancode scanCode;
    scanCode = SDL_GetScancodeFromKey(key);
    if (previousState[scanCode] == 0 && currentStates[scanCode] == 1) {
        return true;
    } return false;
}

bool Input::isQuit() {
    return quit;
}