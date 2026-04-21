#include "Window.h"
#include <iostream>

Window::Window(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error: " << SDL_GetError() << '\n';
        return;
    }
    sdlWindow = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (sdlWindow == nullptr) {
        std::cout << "Error: " << SDL_GetError() << '\n';
    }
};

Window::~Window() {
    if (sdlWindow) {
        SDL_DestroyWindow(sdlWindow);
    }
};

SDL_Window* Window::getSDLWindow() const {
    return sdlWindow;
};
