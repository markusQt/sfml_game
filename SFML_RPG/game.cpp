#include "game.h"




//Constructor Destructor
Game::Game(unsigned int modeWidth, unsigned int modeHeight, const char *title)
{
    this->mModeWidth= modeWidth;
    this->mModeHeight= modeHeight;
    this->title = title;
    initWindow();
    run();
}

Game::~Game()
{
    std::cout << "Game Destructor"<<std::endl;
    delete mWindow;
}

// Mainloop:

void Game::run()
{
    while(mWindow->isOpen()){
       handleEvents();
       render();
    }
}

void Game::initWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(mModeWidth,mModeHeight),title);
    mWindow->setFramerateLimit(60);
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
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
           // Escape Key also raus
            std::cout<< "Links" <<std::endl;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
           // Escape Key also raus
           std::cout<< "Rechts" <<std::endl;
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {

           std::cout<< "Runter" <<std::endl;
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
    if(!texPlayer->loadFromFile("assets/walkingSkel.png",sf::IntRect(0,0,32,32))){
        std::cout << "Textur konnte nicht geladenw erden"<<std::endl;
    }
}

void Game::render()
{
    mWindow->clear();
    // Drawing hier
    mWindow->display();

}


