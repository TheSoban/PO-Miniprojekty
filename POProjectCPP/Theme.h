#ifndef THEME_H
#define THEME_H

#include "SFML/Graphics.hpp"

using namespace std;

class Theme
{
private:
  sf::Color main;
  sf::Color secondary;
  sf::Color food;
  sf::Color snakeHead;
  sf::Color snakeBody;
  sf::Color button;
  sf::Font font;

public:
  Theme();
  Theme(sf::Color main, sf::Color secondary, sf::Color food, sf::Color snakeHead, sf::Color snakeBody, sf::Color button);
  sf::Color &getPrimary();
  sf::Color &getSecondary();
  sf::Color &getFood();
  sf::Color &getSnakeHead();
  sf::Color &getSnakeBody();
  sf::Color &getButton();
  sf::Font &getFont();
};

#endif