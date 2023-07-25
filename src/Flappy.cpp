//declarar tudo
#include "Flappy.hpp"

//construtor
FlappyBird::FlappyBird(){ 
    window = make_shared<sf::RenderWindow>( //criando a janela com ponteiro inteligente 
     sf::VideoMode(1280, 720),
     "Flappy Bird(Remake)",
     sf::Style::Titlebar | sf::Style::Close
    );
    sf::Image Icon = sf::Image { };
	Icon.loadFromFile("assets/game/icon.png");
	window->setIcon(Icon.getSize().x, Icon.getSize().y, Icon.getPixelsPtr());
    
    
    window->setFramerateLimit( 60 );
    gravity = 0;
    space = 100.0f;
    count = frame = 0;
    updateTexture = 0;
    bg.loadFromFile("assets/game/map.jpeg");
    bird_Texture[0].loadFromFile("assets/bird/bird-midflap.png");
    bird_Texture[1].loadFromFile("assets/bird/bird-upflap.png");
    bird_Texture[2].loadFromFile("assets/bird/bird-downflap.png");
    restart_texture.loadFromFile("assets/gameover/restart.png");
    quit_texture.loadFromFile("assets/gameover/quit.png");
    pipe.loadFromFile("assets/game/pipe-green.png");
    font.loadFromFile("assets/gameover/CHERL___.TTF");
    gmText.setFont(font);
    //ponteiros inteligentes para sprites
    background = make_shared<sf::Sprite>();
    bird = make_shared<sf::Sprite>();
    pipetop = make_shared<sf::Sprite>();
    pipeback = make_shared<sf::Sprite>();
    restart = make_shared<sf::Sprite>();
    quit = make_shared<sf::Sprite>();

    background->setTexture(bg);
    bird->setTexture(bird_Texture[0]);
    pipetop->setTexture(pipe);
    pipeback->setTexture(pipe);
    restart->setTexture(restart_texture); 
    quit->setTexture(quit_texture);

    //posicionando o passaro no centro da tela
    bird->setPosition(
    500.0f - bird_Texture[0].getSize().x / 2.f,
    300.0f - bird_Texture[0].getSize().x / 2.f
    );
    bird->setScale(2.f,2.f);
    pipeback->setScale(2.3f,2.3f);
    pipetop->setScale(2.3f,2.3f);
    pipetop->setRotation(180.f);
   

    restart->setScale(.2f,.2f);
    quit->setScale(.2f,.2f);
    restart->setPosition(620,350);
    quit->setPosition(620,470);
}

//eventos
void FlappyBird::events(){ 
    sf::Event event;
    pos_mouse = sf::Mouse::getPosition(*window);
	mouse_coord = window->mapPixelToCoords(pos_mouse);

    while(window->pollEvent(event)){      
        if(event.type == sf::Event::Closed){
            window->close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mouseup = true;
        }
    }
}

//desenhando
void FlappyBird::draw(){ 
    window->clear(sf::Color::Black);
    window->draw(*background);
    window->draw(*bird);
    window->draw(*restart);
    window->draw(*quit);
    window->draw(gmText);
    for(auto &p : pipes){
        window->draw(p);
    }
    window->display();

}
//animação do bird
void FlappyBird::animation(){
    if(frame == 5){
        updateTexture++;
        if(updateTexture == 3){
            updateTexture = 0;
        }
        frame = 0;
    }
    bird->setTexture(bird_Texture[updateTexture],true);
}

//movimentando os pipes
void FlappyBird::movepipes(){
    if (count % 150 == 0 ){ //criando pipe a cada 160
        int pos = rand() % 275 + 175;
        
        pipeback->setPosition(1280, pos+space);
        pipetop->setPosition(1280+120, pos-space);
        pipes.push_back(*pipeback);
        pipes.push_back(*pipetop);
    }

    for (size_t i{}; i < pipes.size(); i++){ 
        if(pipes[i].getGlobalBounds().intersects(bird->getGlobalBounds())){
                GameOver = true;
        }
        if(pipes[i].getPosition().x < -100){    
               pipes.erase(pipes.begin() + i);
        }
        pipes[i].move(-4.f, 0);
        }
}

//movento o passaro 
void FlappyBird::movebird(){
    bird->move(0, gravity); //move o bird somente no y
    gravity += 0.4f; // movimenta a gravidade 
    mouseup == true ? bird->setRotation(-7.f) : bird->setRotation(0); //animação de rotação ao clicar 
}

//chamando as funcoes referentes do jogo
void FlappyBird::game(){
    if(GameOver != true){
    bird->setColor(sf::Color::White);
    quit->setColor(sf::Color::Transparent);
    restart->setColor(sf::Color::Transparent);    
    gmText.setFillColor(sf::Color::Transparent);
    movepipes();
    animation();
    movebird();

    if(mouseup == true){
        gravity = -7.f;
        mouseup = false; 
    }

    }else{
        gameover();
    }
}
//perdeu o jogo
void FlappyBird::gameover(){
    window->draw(*background);
    gmText.setString("GameOver");
    gmText.setFillColor(sf::Color::Black);
    gmText.setCharacterSize(190);
    gmText.setPosition(200,0);
    quit->setColor(sf::Color::White);
    restart->setColor(sf::Color::White); 
    bird->setColor(sf::Color::Transparent);

        for (int i = 0; i < pipes.size(); i++){ 
            
                 pipes.pop_back();
        }

    if(restart->getGlobalBounds().contains(mouse_coord)){
        restartgame();
    }
    
    if(quit->getGlobalBounds().contains(mouse_coord)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            window->close();

        }
    }
}
//reinicia o jogo
void FlappyBird::restartgame(){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            bird->setPosition(
                500.0f - bird_Texture[0].getSize().x / 2.f,
                300.0f - bird_Texture[0].getSize().x / 2.f
             );

         for (int i = 0; i < pipes.size(); i++){ 
                 pipes.pop_back();

        }
          GameOver = false;
          frame = 0;
        }
}

//rodando tudo
void FlappyBird::run(){
    while(window->isOpen()){ //se a janela estiver aberta...
        events();
        draw();
        game();
        count++; //contar frame
        frame++;
        if(count == 300){
            count = 0;
        } 

    }
    
}




