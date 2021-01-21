#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Food.h"
#include "CanvasItem.h"

using namespace std;

class Game : public CanvasItem
{
private:
  Snake player;
  Food food;
  int score;
  int segments;
  bool paused;

public:
  Game();
  Game(int segments);
  void handleKeybordInput(sf::Event event);
  int getScore();
  bool getPaused();
  void setPaused(bool paused);
  void restart();
  void changeFoodLocation();
  bool isOver();
  void update();
  void draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme);
};

#endif