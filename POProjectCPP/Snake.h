#ifndef SNAKE_H
#define SNAKE_H
#include "CanvasItem.h"
#include "Vector.h"
#include <vector>

using namespace std;

class Snake : public CanvasItem
{
private:
  Vector head;
  vector<Vector> body;
  Vector direction;
  bool moveCooldown;
  bool eatingFood;

public:
  Snake();
  Snake(int x, int y);
  void setDirection(int x, int y);
  void resetState();
  void setEatingFood();
  bool isDead(int segments);
  Vector &getPosition();
  vector<Vector> &getBody();
  void update();
  void draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme);
};

#endif