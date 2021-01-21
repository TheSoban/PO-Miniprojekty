#include "Game.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Game::Game()
{
  this->player = Snake();
  this->food = Food(2, 2);
  this->segments = 0;
  this->score = 0;
  this->paused = false;
}

Game::Game(int segments)
{
  this->player = Snake(segments / 2, segments / 2);
  this->food = Food(2, 2);
  this->segments = segments;
  this->score = 0;
  this->changeFoodLocation();
  this->paused = false;
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

int Game::getScore()
{
  return this->score;
}

void Game::setPaused(bool paused)
{
  this->paused = paused;
}

bool Game::getPaused()
{
  return this->paused;
}

bool Game::isOver()
{
  return this->player.isDead(this->segments);
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
        
*/

void Game::handleKeybordInput(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Escape)
    this->paused = !(this->paused);
  if (!(this->paused))
  {
    if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
      this->player.setDirection(-1, 0);
    if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
      this->player.setDirection(1, 0);
    if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
      this->player.setDirection(0, -1);
    if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
      this->player.setDirection(0, 1);
  }
}

void Game::changeFoodLocation()
{
  bool invalid = false;
  do
  {
    this->food = Food(segments);
    if (this->food.getPosition().equals(this->player.getPosition()))
      invalid = true;
    for (Vector part : this->player.getBody())
    {
      if (part.equals(this->food.getPosition()))
        invalid = true;
    }
  } while (invalid);
}

void Game::restart()
{
  this->player = Snake(this->segments / 2, this->segments / 2);
  this->food = Food();
  this->score = 0;
  this->changeFoodLocation();
  this->paused = false;
}

void Game::update()
{
  if (!(this->paused))
  {
    this->player.update();
    if (this->player.getPosition().equals(this->food.getPosition()))
    {
      this->player.setEatingFood();
      score += 1;
      this->changeFoodLocation();
    }
  }
}

void Game::draw(int windowSize, int segments, sf::RenderWindow *window, Theme &theme)
{
  CanvasItem *food = &(this->food);
  CanvasItem *player = &(this->player);
  food->draw(windowSize, segments, window, theme);
  player->draw(windowSize, segments, window, theme);
}