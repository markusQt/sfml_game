#include "game.h"

// Static Functions



// initialize Functions
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "SFML in Gameclass");

}


//Constructor Destructor
Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}
//Functions
void Game::updateSFML_Event()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFML_Event();
}

void Game::render()
{
    this->window->clear();
    //Stuff to Render here

    this->window->display();
}

void Game::run()
{
    while (window->isOpen())
    {
        this->update();
        this->render();
    }
}

