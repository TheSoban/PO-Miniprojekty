#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Theme.h"
#include "Game.h"
#include "Store.h"
#include "Draw.h"

using namespace std;

class Menu
{
private:
  int windowSize;
  int framerate;
  int segments;
  int money;
  string tab;
  Game game;
  Draw drawing;
  Store store;
  sf::RenderWindow *window;

public:
  Menu(int windowSize, sf::RenderWindow *window);
  sf::RenderWindow *getWindow();
  void selectTheme(int index);
  void handleKeybordInput(sf::Event event);
  void handleMouseInput(sf::Event event);
  void setFramerate(int framerate);
  int getFramerate();
  void update();
  void draw();
};

#endif