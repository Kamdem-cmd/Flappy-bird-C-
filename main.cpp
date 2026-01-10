#include "Game.h"

int main(){
    std::cout<<"FLAPPY Bird en cours de developpement ...\n";
    Game game;

    game.Init();

    game.Run();
    
    game.Shutdown();
    
    std::cout<<"Fermeture de l'application effective ...\n";
    return 0;
}



