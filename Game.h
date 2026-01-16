#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include <vector>
#include "external/imgui/imgui.h"
#include "external/imgui/backends/imgui_impl_sdl3.h"
#include "external/imgui/backends/imgui_impl_sdlrenderer3.h"

#define HEIGHT 720
#define WIDTH 1024

// Structure player
struct Entity
{
    float x, y; // position
    float w, h; // taille

    float velocityY = 0.0f;
    SDL_Texture* Texture = nullptr;
    SDL_Surface* surface = nullptr;
    int channel;
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
    bool hasEntitiesIntersect(Entity a, Entity b);
    void Reset();
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool running;
    const bool* keyboard = nullptr;         // Etat clavier

    const float gravity = 98.0f;
    float impulsion = 4.0f;
    float speed = 100.0f;
    double fps = 0.0;

    Entity bird;

    Uint64 tickPrecedent;
    std::vector<Entity> entities;

    unsigned char* pixels = nullptr;
    

};