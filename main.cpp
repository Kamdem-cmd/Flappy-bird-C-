#include "Game.h"



void RenderEntities(SDL_Renderer* renderer, const std::vector<Entity>& entities);

int main(){
    std::cout<<"FLAPPY Bird en cours de developpement ...\n";

    // initialise SDL3
    int init = SDL_Init(SDL_INIT_VIDEO);
    if(init < 0){
        std::cerr << "Erreur d'initialisation de SDL3 " << SDL_GetError() << std::endl;
        return 1;
    }

    // initialisation de la fenetre
    SDL_Window* window = SDL_CreateWindow("Flappy Bird", WIDTH, HEIGHT, 0);
    if(!window){
        std::cerr<< "Erreur d'initialisation de la fenetre " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1; 
    }

    // initialisation du rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if(!renderer){
        std::cerr << "Erreur d'initialisation du rendu " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        return 1;
    }

    // Activé le VSync
    SDL_SetRenderVSync(renderer, 1);

    bool running = true;
    SDL_Event event;
    Uint64 tickPrecedent= SDL_GetPerformanceCounter();
    Uint64 tickActuel= 0;
    double deltaTime = 0.0;
    int fps = 0;
    int previousFPS = 0;
    const double MAX_DELTA = 0.05; // 50 ms
    double fpsTimer = 0.0;
    int frameCount = 0;
    float gravity = 98.0f;
    float masse = 3.0f;

    Entity bird = {200, 150, 100, 50};

    std::vector<Entity> entities;
    
    // Bloc1
    entities.push_back({500.0f, 0.0f, 50.0f, 270.0f});
    entities.push_back({500.0f, 720.0f - 350.0f, 50.0f, 350.0f});
    // Bloc2
    entities.push_back({750.0f, 0.0f, 50.0f, 325.0f});
    entities.push_back({750.0f, 720.0f - 300.0f, 50.0f, 325.0f});
    // Bloc3
    entities.push_back({1000.0f, 0.0f, 50.0f, 250.0f});
    entities.push_back({1000.0f, 720.0f - 350.0f, 50.0f, 350.0f});


    // boucle principale
    while(running){
        // gestion d'evenement
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                running = false;
                std::cout<<"Quit ...\n";
            }
        }
        // Calcul du deltaTime
        tickActuel = SDL_GetPerformanceCounter();
        deltaTime = (double)(tickActuel - tickPrecedent) / (double)SDL_GetPerformanceFrequency();
        tickPrecedent = tickActuel;

        if (deltaTime > MAX_DELTA) deltaTime = MAX_DELTA;

        // Etat clavier
        const bool* keyboard = SDL_GetKeyboardState(nullptr);
        bool moveUp = keyboard[SDL_SCANCODE_SPACE];

        // Mise à jour de la position du rectangle apres input
        if(moveUp){
            std::cout<<"UP ...\n";
            bird.y -= 4 * masse * gravity * deltaTime;
        }
        // Mise à jour de la position du rectangle
        bird.y += masse * gravity * deltaTime;

        // Chargement du rendu
        SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255); 
        SDL_RenderClear(renderer); 

        // Ajout du rectangle au rendu
        SDL_FRect rectBird = {bird.x, bird.y, bird.w, bird.h};
        SDL_RenderRect(renderer, &rectBird);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);   // AGBR
        SDL_RenderFillRect(renderer, &rectBird);

        // Ajoutes des obstacles au rendu
        SDL_SetRenderDrawColor(renderer, 45, 50, 255, 255);
        RenderEntities(renderer, entities);


        // affichage du rendu
        SDL_RenderPresent(renderer);
    
        fpsTimer += deltaTime;
        frameCount++;

        if (fpsTimer >= 1.0)
        {
            double fps = frameCount / fpsTimer;
            std::cout << "FPS: " << fps << std::endl;

            fpsTimer -= 1.0; // au lieu de = 0.0
            frameCount = 0;
        }

    }
    //  destruction du rendu
    SDL_DestroyRenderer(renderer);

    //  destruction de la fenetre
    SDL_DestroyWindow(window);

    //  Quitter l'application
    SDL_Quit();
    std::cout<<"Fermeture de l'application effective ...\n";
    return 0;
}


void RenderEntities(SDL_Renderer* renderer, const std::vector<Entity>& entities)
{
    for (const auto& e : entities)
    {
        SDL_FRect rect = { e.x, e.y, e.w, e.h };
        SDL_RenderFillRect(renderer, &rect);
    }
}
