#pragma once
#include "SDL.h"

using Event = SDL_Event;
using KeyCode = SDL_Keycode;

class Input {
    public:
        void update();
        bool isHeld(KeyCode key);
        bool isPressed(KeyCode key);
        bool isQuit();
    private:
        const Uint8* currentStates = nullptr;
        Uint8 previousState[SDL_NUM_SCANCODES] = {};
        bool quit = false;
};