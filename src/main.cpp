//rodar game
#include "Flappy.hpp"

int main (){
    
    srand(0);
    auto flappy = make_shared<FlappyBird>();
    flappy->run();

    return EXIT_SUCCESS;
}