#ifndef DRAW_H
#define DRAW_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Theme.h"
#include "Store.h"
#include "Game.h"

using namespace std;

class Draw
{
private:
  Theme *theme;
  int windowSize;
  int gridTile;
  int segments;
  sf::RenderWindow *window;
  void drawRectangle(float posX, float posY, float sizeX, float sizeY, sf::Color &color);
  void drawRectangleWithOutline(float posX, float posY, float sizeX, float sizeY, sf::Color &color);
  void drawButton(string text, float posX, float posY, float sizeX, float sizeY, float textSize);

public:
  Draw();
  Draw(sf::RenderWindow *window, Theme *theme, int windowSize, int segments);
  void setTheme(Theme *theme);
  void background();
  void mainMenu();
  void difficultyMenu();
  void game(Game &gameRef);
  void endGame(Game &gameRef);
  void store(Store &storeRef, int money);
};

#endif