#include "Game.h"

#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"

const float FLOOR = 720.0f;
const float TOP = 0.0f;
bool GameOver = false;


bool Game::Init(){
    // initialise SDL3
    int init = SDL_Init(SDL_INIT_VIDEO);
    if(init < 0){
        std::cerr << "Erreur d'initialisation de SDL3 " << SDL_GetError() << std::endl;
        return false;
    }

    // initialisation de la fenetre
    window = SDL_CreateWindow("Flappy Bird", WIDTH, HEIGHT, 0);
    if(!window){
        std::cerr<< "Erreur d'initialisation de la fenetre " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false; 
    }

    // initialisation du rendu
    renderer = SDL_CreateRenderer(window, nullptr);
    if(!renderer){
        std::cerr << "Erreur d'initialisation du rendu " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        return false;
    }

    // ImgUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    // Activé le VSync
    SDL_SetRenderVSync(renderer, 1);

    // Player
    bird = {200, 150, 70, 50};
    // entities.push_back(bird);

    // Bloc1
    entities.push_back({500.0f, 0.0f, 50.0f, 270.0f});
    entities.push_back({500.0f, 720.0f - 350.0f, 50.0f, 350.0f});
    // Bloc2
    entities.push_back({750.0f, 0.0f, 50.0f, 325.0f});
    entities.push_back({750.0f, 720.0f - 300.0f, 50.0f, 325.0f});
    // Bloc3
    entities.push_back({1000.0f, 0.0f, 50.0f, 250.0f});
    entities.push_back({1000.0f, 720.0f - 350.0f, 50.0f, 350.0f});

    int width, height, channels;
    width = (int)bird.w;
    height = (int)bird.h;
    pixels = stbi_load(
        "assets/img/flappy.png",
        &width,
        &height,
        &bird.channel,
        4
    );

    if (!pixels){
        SDL_Log("Erreur chargement image");
        return false;
    }

    bird.surface = SDL_CreateSurfaceFrom(
        width,
        height,
        SDL_PIXELFORMAT_RGBA32,
        pixels,
        width * 4
    );

    bird.Texture = SDL_CreateTextureFromSurface(renderer, bird.surface);

    SDL_DestroySurface(bird.surface);
    stbi_image_free(pixels);
    return true;
}

void Game::Run(){
    running = true;
    Uint64 tickActuel= 0;
    double deltaTime = 0.0;
    const double MAX_DELTA = 0.05; // 50 ms
    double fpsTimer = 0.0;
    int frameCount = 0;

    // boucle du jeu
    while (running)
    {
        // Calcul du deltaTime
        tickActuel = SDL_GetPerformanceCounter();
        deltaTime = (double)(tickActuel - tickPrecedent) / (double)SDL_GetPerformanceFrequency();
        tickPrecedent = tickActuel;

        if (deltaTime > MAX_DELTA) deltaTime = MAX_DELTA;

        // Calcul des FPS
        fpsTimer += deltaTime;
        frameCount++;

        if (fpsTimer >= 1.0)
        {
            fps = frameCount / fpsTimer;
            std::cout << "FPS: " << fps << std::endl;

            fpsTimer -= 1.0; // au lieu de = 0.0
            frameCount = 0;
        }

        // HandleEvents
        HandleEvents();

        // Upgrade
        Update(deltaTime);

        // Render
        Render();
    }
}

void Game::Shutdown(){
    entities.clear();

    //  Liberation de ressource stb_image
    SDL_DestroyTexture(bird.Texture);

    //  destruction ImgUI
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    //  destruction du rendu
    SDL_DestroyRenderer(renderer);

    //  destruction de la fenetre
    SDL_DestroyWindow(window);

    //  Quitter l'application
    SDL_Quit();
}

void Game::HandleEvents(){
    SDL_Event event;

    // gestion d'evenement
    while(SDL_PollEvent(&event)){
        ImGui_ImplSDL3_ProcessEvent(&event);
        if(event.type == SDL_EVENT_QUIT){
            running = false;
            std::cout<<"Quit ...\n";
        }
    }
}

void Game::Update(double deltaTime){
    
    if (!GameOver)
    {
        // Etat clavier
        keyboard = SDL_GetKeyboardState(nullptr);

        // Mise à jour de la position du rectangle
        bird.y += gravity * (float)deltaTime;
        
        // Mise à jour de la position du rectangle apres input
        if(keyboard[SDL_SCANCODE_SPACE]){
            std::cout<<"UP ...\n";
            
            bird.y -= impulsion * gravity * deltaTime;
        }

        // forcer l'affichage du joueur dans les limites de l'écran
        if(bird.y < TOP){
            bird.y = TOP;
        }
        if((bird.y + bird.h) > FLOOR){
            bird.y = FLOOR - bird.h;
        }
    
        // Deplacement tuyaux
        for (auto& e : entities)
        {
            e.x -= speed * deltaTime; // vitesse temporaire
            if(hasEntitiesIntersect(bird, e)){
                std::cout << "Game Over, Objet touché.\n";
                GameOver = true;
            }
        }
    }else{
        // Etat clavier
        keyboard = SDL_GetKeyboardState(nullptr);
        if(keyboard[SDL_SCANCODE_R]){
            Reset();
            GameOver = false;
        }
    }
}
    

void Game::Render(){
    // Chargement du rendu
    SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255); 
    SDL_RenderClear(renderer); 

    

    // Ajout du joueur au rendu
    SDL_FRect rectBird = {bird.x, bird.y, bird.w, bird.h};
    SDL_RenderRect(renderer, &rectBird);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);   // AGBR
    SDL_RenderFillRect(renderer, &rectBird);
    SDL_RenderTexture(renderer, bird.Texture, nullptr, &rectBird);

    // Ajoutes des obstacles au rendu
    SDL_SetRenderDrawColor(renderer, 45, 50, 255, 255);
    RenderEntities(renderer, entities);

    // ImgUI render
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Debug");
    ImGui::Text("FPS: %.1f", fps);
    ImGui::Text("Player X: %.2f", bird.x);
    ImGui::Text("Player Y: %.2f", bird.y);
    ImGui::Text("Gavité: %.1f", gravity);
    ImGui::Text("impulsion: %.1f", impulsion);
    ImGui::Text("speed: %.1f", speed);
    ImGui::End();

    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);

    // affichage du rendu
    SDL_RenderPresent(renderer);
}

void Game::RenderEntities(SDL_Renderer* renderer, const std::vector<Entity>& entities)
{
    for (const auto& e : entities)
    {
        SDL_FRect rect = { e.x, e.y, e.w, e.h };
        SDL_RenderFillRect(renderer, &rect);
    }
}

bool Game::hasEntitiesIntersect(Entity a, Entity b){
    return a.x < b.x + b.w &&
           a.x + a.w > b.x &&
           a.y < b.y + b.h &&
           a.y + a.h > b.y;
}

void Game::Reset(){
    bird.y = 150.0f;

    entities.clear();

    // Bloc1
    entities.push_back({500.0f, 0.0f, 50.0f, 270.0f});
    entities.push_back({500.0f, 720.0f - 350.0f, 50.0f, 350.0f});
    // Bloc2
    entities.push_back({750.0f, 0.0f, 50.0f, 325.0f});
    entities.push_back({750.0f, 720.0f - 300.0f, 50.0f, 325.0f});
    // Bloc3
    entities.push_back({1000.0f, 0.0f, 50.0f, 250.0f});
    entities.push_back({1000.0f, 720.0f - 350.0f, 50.0f, 350.0f});
}