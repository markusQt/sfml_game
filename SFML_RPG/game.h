#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
public:

    //Constructor Destructor
    Game();
    ~Game();

    //Functions
    void updateSFML_Event();
    void update();
    void render();
    void run();

private:
    // initialize Functions
    void initWindow();
    // Static Functions

    //Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

};

#endif // GAME_H
