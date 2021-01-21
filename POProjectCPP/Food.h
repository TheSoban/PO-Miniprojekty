#ifndef FOOD_H
#define FOOD_H
#include "CanvasItem.h"
#include "Vector.h"
#include "Utils.h"

using namespace std;

class Food : public CanvasItem
{
private:
  Vector position;

public:
  Food();
  Food(int segments);
  Food(int x, int y);
  void setPosition(int x, int y);
  Vector &getPosition();
  void update();
  void draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme);
};

#endif