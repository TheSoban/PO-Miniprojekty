#include <SFML/Graphics.hpp>
#include "Menu.h"
int main()
{
    srand(time(NULL));
    int windowSize = 900;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(windowSize, windowSize), "Snake");

    Menu menu(windowSize, window);
    menu.getWindow()->setTitle("Snake");

    while (menu.getWindow()->isOpen())
    {
        sf::Event event;
        while (menu.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menu.getWindow()->close();
            if (event.type == sf::Event::Resized)
                menu.getWindow()->setSize(sf::Vector2u(windowSize, windowSize));
            if (event.type == sf::Event::KeyReleased)
                menu.handleKeybordInput(event);
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
                menu.handleMouseInput(event);
        }

        menu.update();
        menu.draw();

        menu.getWindow()->display();
    }

    return 0;
}