#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>

#define HEIGHT 720
#define WIDTH 1024

// Structure player
struct Entity
{
    float x, y; // position
    float w, h; // taille
};

class Game
{
public:
    bool Init();
    void Run();
    void Shutdown();

private:
    void HandleEvents();
    void Update(double deltaTime);
    void Render();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;


    Uint64 tickPrecedent;
    std::vector<Entity> entities;

}