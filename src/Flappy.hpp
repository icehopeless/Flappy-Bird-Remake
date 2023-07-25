//criar tudo
#pragma once 

#include <iostream>
#include <cstdlib>
#include "SFML/Graphics.hpp"
#include <memory>

using namespace std;

class FlappyBird{
    float frame, space, gravity;
    int count;
    shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para ser deletado automaticamente
    shared_ptr<sf::Sprite> bird, pipetop, pipeback, background,restart, quit; // ponteiros inteligentes para fazerem alocações dinâmicas em  Sprites
    sf::Texture bird_Texture[3], pipe,bg,restart_texture,quit_texture;  
    vector<sf::Sprite> pipes; //vetor inteligente para guardar os pipes e apaga-los
    int updateTexture;
    bool mouseup, GameOver;
    sf::Font font;
    sf::Text gmText;
   	sf::Vector2i pos_mouse;
	sf::Vector2f mouse_coord;
   
   protected:
   void events();
   void draw();
   void game(); //responsavel por rodar tudo que envolve o jogo
   void animation();
   void movepipes();
   void movebird();
   void gameover();
   void creditos();
   void restartgame();

   public:
   FlappyBird();
   void run();

};