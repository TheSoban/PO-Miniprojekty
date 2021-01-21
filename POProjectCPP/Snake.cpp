#include "Snake.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Snake::Snake()
{
  this->head = Vector();
  this->body = vector<Vector>();
  this->direction = Vector(1, 0);
  this->moveCooldown = false;
  this->eatingFood = false;
}

Snake::Snake(int x, int y)
{
  this->head = Vector(x, y);
  this->body = vector<Vector>();
  this->body.push_back(Vector(x - 1, y));
  this->direction = Vector(1, 0);
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

Vector &Snake::getPosition()
{
  return this->head;
}

vector<Vector> &Snake::getBody()
{
  return this->body;
}

void Snake::setEatingFood()
{
  this->eatingFood = true;
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
      
*/

void Snake::setDirection(int x, int y)
{
  Vector move(x, y);
  if (!(this->moveCooldown))
  {
    if (!move.equals(this->direction.copy().multiplyScalar(-1)) && !move.equals(this->direction))
    {
      this->direction = move;
      this->moveCooldown = true;
    }
  }
}

void Snake::resetState()
{
  this->moveCooldown = false;
  this->eatingFood = false;
}

bool Snake::isDead(int segments)
{
  if (this->head.getX() < 0 || this->head.getX() >= segments || this->head.getY() < 0 || this->head.getY() >= segments)
    return true;
  for (Vector part : this->body)
  {
    if (part.equals(this->head))
      return true;
  }
  return false;
}

void Snake::draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme)
{
  float tileSize = windowSize / segments;

  sf::RectangleShape head(sf::Vector2f(tileSize, tileSize));
  head.setFillColor(theme.getSnakeHead());
  head.setPosition(this->head.getX() * tileSize, this->head.getY() * tileSize);
  window->draw(head);

  for (Vector part : this->body)
  {
    sf::RectangleShape bodyPart(sf::Vector2f(tileSize, tileSize));
    bodyPart.setFillColor(theme.getSnakeBody());
    bodyPart.setPosition(part.getX() * tileSize, part.getY() * tileSize);
    window->draw(bodyPart);
  }
}

void Snake::update()
{
  this->body.push_back(this->head.copy());
  this->head.add(this->direction);
  if (!this->eatingFood)
    this->body.erase(this->body.begin());
  this->resetState();
}
