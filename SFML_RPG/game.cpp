#include "game.h"




//Constructor Destructor
Game::Game(unsigned int modeWidth, unsigned int modeHeight, const char *title)
{
    this->mModeWidth= modeWidth;
    this->mModeHeight= modeHeight;
    this->title = title;
    initWindow();
    loadImageAndDraw();
    run();
}

Game::~Game()
{
    std::cout << "Game Destructor"<<std::endl;
    delete mWindow;
    delete texPlayer;
    delete playerSprite;
}

// Mainloop:

void Game::run()
{   sf::Clock clock;
    sf::Time zeitdauer;
    while(mWindow->isOpen()){
       clock.restart();
       handleEvents();
       render();
       zeitdauer= clock.getElapsedTime();
       std::cout << "FPS?: " << zeitdauer.asMilliseconds() << std::endl;
    }
}

void Game::initWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(mModeWidth,mModeHeight),title);
    mWindow->setFramerateLimit(50);
}

void Game::handleEvents()
{
    sf::Event event;
    while(mWindow->pollEvent(event)){
        switch (event.type) {
            case  sf::Event::Closed: mWindow->close();
            break;
        case  sf::Event::KeyPressed:handleKeyEvents();
            break;
        case  sf::Event::MouseButtonPressed:handleMausEvents();
            break;
        default:
            break;
        }
    }
}

void Game::handleKeyEvents()
{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
           // Escape Key also raus
           mWindow->close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {

            std::cout<< "Hoch" <<std::endl;
            playerSprite->move(0.0f,-speed);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
           // Escape Key also raus
            std::cout<< "Links" <<std::endl;
            playerSprite->move(-speed,0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
           std::cout<< "Rechts" <<std::endl;
                              //WIDTH -HEIGHT
           playerSprite->move(speed,0.0f);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {

           std::cout<< "Runter" <<std::endl;
           playerSprite->move(0.0f,speed);
        }


}

void Game::handleMausEvents()
{
    if (sf::Mouse::isButtonPressed((sf::Mouse::Right)))
    {
       std::cout<< "Rechte Maustaste" <<std::endl;
    }
    if (sf::Mouse::isButtonPressed((sf::Mouse::Left)))
    {
       std::cout<< "Linke Maustaste" <<std::endl;
    }
}

void Game::loadImageAndDraw()
{
    texPlayer = new sf::Texture();
    if(!texPlayer->loadFromFile("assets/walkingSkel.png",sf::IntRect(0,0,270,300))){
        std::cout << "Textur konnte nicht geladen werden"<<std::endl;
    }else{
        std::cout << "Textur erfolgreich geladen erden"<<std::endl;
        playerSprite = new sf::Sprite();
        playerSprite->setTexture(*texPlayer);

    }
}

void Game::render()
{
    mWindow->clear();
    // Drawing hier
    mWindow->draw(*playerSprite);
    mWindow->display();

}


