#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Markus hat SFML am Laufen!" );
       sf::CircleShape shape(100.f);
       shape.setFillColor(sf::Color::Green);

       while (window.isOpen())
       {
           sf::Event event;
           while (window.pollEvent(event))
           {
               if (event.type == sf::Event::Closed)
                   window.close();
           }

           window.clear();
           window.draw(shape);
           window.display();
       }

    return 0;
}