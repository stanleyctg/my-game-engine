# MyEngine

A custom 2D game engine built from scratch in C++ using SDL2.

## Why?

Most developers use Unity or Unreal and never understand what's happening underneath. This engine exists to answer that question.

Built incrementally, driven by real game requirements. Each game built on top surfaces new problems. Those problems become engine features. The engine grows organically — no over-engineering upfront, only what a real game needs.

## Architecture

    Engine            owns all systems, runs the loop
    ├── ECS           entity and component storage
    ├── Input         keyboard state (press / hold / release)
    ├── Physics       gravity, collision, boundary clamping
    └── Renderer      draws entities to screen

    IGame             interface every game implements
    └── YourGame      your rules, your entities, your UI

    ## How it works

The engine and the game are intentionally separate. The engine provides the tools — a window, a loop, physics, rendering, input. The game decides how to use them.

A game developer implements the IGame interface and the engine runs it. The engine never knows what game it's running. Swap the game out and the engine doesn't change.

## Current Features

- Entity Component System (ECS)
- Fixed 60fps game loop
- SDL2 rendering
- AABB collision detection and resolution
- Gravity
- Keyboard input (press, hold, release)
- Boundary clamping

## Games Built With This Engine

| Game | Status | What it taught the engine |
|------|--------|--------------------------|
| Pong | In progress | Per entity input, text rendering, scoring |

## Tech Stack

- C++17
- SDL2
- CMake
