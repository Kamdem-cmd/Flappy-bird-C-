#include <SDL3/SDL.h>
#include <iostream>

#define HEIGHT 720
#define WIDTH 1024


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


        // Chargement du rendu
        SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255); 
        SDL_RenderClear(renderer); 

        // affichage du rendu
        SDL_RenderPresent(renderer);

        // if(fps - previousFPS !=0){
        //     std::cout<<"FPS: " << fps <<std::endl;
        // }

        // previousFPS = fps;
    
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