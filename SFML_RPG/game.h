#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
public:

    //Constructor Destructor
    Game(unsigned int modeWidth, unsigned int modeHeight, const char * title);
    ~Game();




private:
 void run();
 void initWindow();
 void handleEvents();
 void handleKeyEvents();
 void handleMausEvents();
 void loadImageAndDraw();
 void render();
 int countWalking =0;
 const float speed = 3;
 unsigned int mModeWidth;
 unsigned int mModeHeight;
 const char * title;
 sf::RenderWindow * mWindow;
 sf::Texture *texPlayer;
 sf::Sprite *playerSprite;

};

#endif // GAME_H
