//rodar game
#include "Flappy.hpp"
#include "Flappy.cpp"
int main (){
    srand(time(0));
     FlappyBird flappy;
    flappy.run();
    
    return EXIT_SUCCESS;
}