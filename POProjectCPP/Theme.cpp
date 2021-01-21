#include "Theme.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Theme::Theme()
{
  this->main = sf::Color(0, 0, 0);
  this->secondary = sf::Color(0, 0, 0);
  this->food = sf::Color(0, 0, 0);
  this->snakeHead = sf::Color(0, 0, 0);
  this->snakeBody = sf::Color(0, 0, 0);
  this->button = sf::Color(0, 0, 0);
  this->font.loadFromFile("assets/RobotoMono.ttf");
}

Theme::Theme(sf::Color main, sf::Color secondary, sf::Color food, sf::Color snakeHead, sf::Color snakeBody, sf::Color button)
{
  this->main = main;
  this->secondary = secondary;
  this->food = food;
  this->snakeHead = snakeHead;
  this->snakeBody = snakeBody;
  this->button = button;
  this->font.loadFromFile("assets/RobotoMono.ttf");
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

sf::Color &Theme::getPrimary()
{
  return this->main;
}

sf::Color &Theme::getSecondary()
{
  return this->secondary;
}

sf::Color &Theme::getFood()
{
  return this->food;
}

sf::Color &Theme::getSnakeHead()
{
  return this->snakeHead;
}

sf::Color &Theme::getSnakeBody()
{
  return this->snakeBody;
}

sf::Color &Theme::getButton()
{
  return this->button;
}

sf::Font &Theme::getFont()
{
  return this->font;
}