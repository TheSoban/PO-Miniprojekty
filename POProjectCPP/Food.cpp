#include "Food.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Food::Food()
{
  this->position = Vector();
  this->setPosition(0, 0);
}

Food::Food(int segments)
{
  this->position = Vector();
  this->setPosition(Utils::getRandomInt(0, segments), Utils::getRandomInt(0, segments));
}

Food::Food(int x, int y)
{
  this->position = Vector();
  this->setPosition(x, y);
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

Vector &Food::getPosition()
{
  return this->position;
}

void Food::setPosition(int x, int y)
{
  this->position.setX(x);
  this->position.setY(y);
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
        
*/

void Food::update() {}

void Food::draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme)
{
  float tileSize = windowSize / segments;
  sf::RectangleShape food(sf::Vector2f(tileSize, tileSize));
  food.setFillColor(theme.getFood());
  food.setPosition(this->position.getX() * tileSize, this->position.getY() * tileSize);
  window->draw(food);
}