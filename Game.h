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
    void RenderEntities(SDL_Renderer* renderer, const std::vector<Entity>& entities);

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool running;
    const bool* keyboard = nullptr;         // Etat clavier

    float gravity = 98.0f;
    float masse = 3.0f;
    float speed = 100.0f;

    Entity bird;

    Uint64 tickPrecedent;
    std::vector<Entity> entities;

};