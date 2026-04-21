#pragma once
#include <SDL.h>

class Window {
    public:
        Window(const char* title, int width, int height);
        ~Window();
        SDL_Window* getSDLWindow() const;
    private:
        SDL_Window* sdlWindow = nullptr;
};