#include <SDL.h>
#include <iostream>
#include "Engine.h"

int main() {
    Engine engine;
    engine.init();
    engine.run();
    engine.shutdown();
    return 0;
}