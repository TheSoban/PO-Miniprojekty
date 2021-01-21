#include "Menu.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Menu::Menu(int windowSize, sf::RenderWindow *window) : window(nullptr)
{
  this->tab = "mainMenu";
  this->windowSize = windowSize;
  this->segments = 30;
  this->money = 70;
  this->window = window;
  this->store = Store();
  this->drawing = Draw(window, &(store.getSelectedProduct()), windowSize, this->segments);
  this->game = Game(this->segments);
  this->setFramerate(10);
  this->selectTheme(0);
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

sf::RenderWindow *Menu::getWindow()
{
  return this->window;
}

int Menu::getFramerate()
{
  return this->framerate;
}

void Menu::setFramerate(int framerate)
{
  this->framerate = framerate;
  this->window->setFramerateLimit(framerate);
}

void Menu::selectTheme(int index)
{
  this->store.selectItem(index, this->money);
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
        
*/

void Menu::handleKeybordInput(sf::Event event)
{
  if (this->tab == "game")
    this->game.handleKeybordInput(event);
}

void Menu::handleMouseInput(sf::Event event)
{
  float tileSize = this->windowSize / this->segments;
  int x = event.mouseButton.x / tileSize;
  int y = event.mouseButton.y / tileSize;
  if (this->tab == "mainMenu")
  {
    if (x >= 6 && x <= 24 && y >= 12 && y <= 16)
      this->tab = "difficultyMenu";
    if (x >= 6 && x <= 24 && y >= 18 && y <= 22)
      this->tab = "store";
    if (x >= 6 && x <= 24 && y >= 24 && y <= 28)
      this->window->close();
  }
  else if (this->tab == "difficultyMenu")
  {
    if (x >= 6 && x <= 24 && y >= 6 && y <= 10)
    {
      this->setFramerate(10);
      this->game.restart();
      this->tab = "game";
    }
    if (x >= 6 && x <= 24 && y >= 12 && y <= 16)
    {
      this->setFramerate(15);
      this->game.restart();
      this->tab = "game";
    }
    if (x >= 6 && x <= 24 && y >= 18 && y <= 22)
    {
      this->setFramerate(20);
      this->game.restart();
      this->tab = "game";
    }
    if (x >= 6 && x <= 24 && y >= 24 && y <= 28)
    {
      this->setFramerate(25);
      this->game.restart();
      this->tab = "game";
    }
  }
  else if (this->tab == "store")
  {
    for (int i = 0; i < this->store.getItems().size(); i++)
    {
      if (x >= (3 + 9 * i) && x <= (9 + 9 * i) && y >= 13 && y <= 16)
      {
        this->selectTheme(i);
      }
    }
    if (x >= 6 && x <= 24 && y >= 24 && y <= 28)
      this->tab = "mainMenu";
  }
  else if (this->tab == "endGame")
  {
    if (x >= 8 && x <= 22 && y >= 16 && y <= 19)
    {
      this->game.restart();
      this->tab = "game";
    }
    if (x >= 8 && x <= 22 && y >= 21 && y <= 24)
      this->tab = "mainMenu";
  }
  else if (this->tab == "game" && this->game.getPaused())
  {
    if (x >= 8 && x <= 22 && y >= 11 && y <= 14)
    {
      this->game.setPaused(false);
    }
    if (x >= 8 && x <= 22 && y >= 16 && y <= 19)
      this->tab = "mainMenu";
  }
}

void Menu::update()
{
  if (this->tab == "game")
  {
    this->game.update();
    if (this->game.isOver())
    {
      this->tab = "endGame";
      this->money += this->game.getScore();
    }
  }
}

void Menu::draw()
{
  this->drawing.setTheme(&(store.getSelectedProduct()));
  this->drawing.background();
  if (this->tab == "mainMenu")
    this->drawing.mainMenu();
  if (this->tab == "difficultyMenu")
    this->drawing.difficultyMenu();
  if (this->tab == "game")
    this->drawing.game(this->game);
  if (this->tab == "endGame")
    this->drawing.endGame(this->game);
  if (this->tab == "store")
    this->drawing.store(this->store, this->money);
}