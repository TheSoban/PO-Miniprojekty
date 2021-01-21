#ifndef CANVASITEM_H
#define CANVASITEM_H

#include "SFML/Graphics.hpp"
#include "Theme.h"

using namespace std;

class CanvasItem
{
public:
  virtual void update() = 0;
  virtual void draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme) = 0;
};

#endif