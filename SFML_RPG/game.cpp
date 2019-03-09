#include "game.h"
#include <istream>
#include <sstream>




//Constructor Destructor
Game::Game(unsigned int modeWidth, unsigned int modeHeight, const char *title)
{
    this->mModeWidth= modeWidth;
    this->mModeHeight= modeHeight;
    this->title = title;
    playerSprite = new sf::Sprite();
    texPlayer = new sf::Texture();
    loadImageAndDraw();
    initWindow();
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
       handleEvents();
       render();
    }
}

void Game::initWindow()
{
    mWindow = new sf::RenderWindow(sf::VideoMode(mModeWidth,mModeHeight),title);
    mWindow->setFramerateLimit(15);
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
            playerSprite->setTextureRect(sf::IntRect(countWalking*30,65*1,30,65));
            playerSprite->move(0.0f,-speed);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            std::cout<< "Links" <<std::endl;
            playerSprite->setTextureRect(sf::IntRect(countWalking*30,65*2,30,65));
            playerSprite->move(-speed,0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
           std::cout<< "Rechts" <<std::endl;
                              //WIDTH -HEIGHT
           playerSprite->setTextureRect(sf::IntRect(countWalking*30,65*3,30,65));
           playerSprite->move(speed,0.0f);
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {

           std::cout<< "Runter" <<std::endl;
           playerSprite->setTextureRect(sf::IntRect(countWalking*30,0,30,65));
           playerSprite->move(0.0f,speed);
        }

        countWalking++;

        if (countWalking==3){
            countWalking=0;
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

    if(!texPlayer->loadFromFile("assets/femalewalk.png"))
    {
        std::cout << "Textur konnte nicht geladen werden"<<std::endl;
    }else{
        std::cout << "Textur erfolgreich geladen erden"<<std::endl;
        playerSprite->setTexture(*texPlayer);
        playerSprite->setTextureRect(sf::IntRect(0,0,30,65));
        playerSprite->setPosition(400 ,300 );


    }
}

void Game::render()
{
    mWindow->clear();
    // Drawing hier
    mWindow->draw(*playerSprite);
    mWindow->display();

}


