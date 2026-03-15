#include <SDL.h>
#include <iostream>
#include "engine.h"

int main() {
    Engine engine;
    engine.init();
    engine.run();
    engine.shutdown();
    return 0;
}