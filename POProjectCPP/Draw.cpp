#include "Draw.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Draw::Draw() {}

Draw::Draw(sf::RenderWindow *window, Theme *theme, int windowSize, int segments) : window(nullptr), theme(nullptr)
{
  this->window = window;
  this->theme = theme;
  this->windowSize = windowSize;
  this->gridTile = windowSize / segments;
  this->segments = segments;
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

void Draw::setTheme(Theme *theme)
{
  this->theme = theme;
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
        
*/

void Draw::drawRectangle(float posX, float posY, float sizeX, float sizeY, sf::Color &color)
{
  sf::RectangleShape rect(sf::Vector2f(this->gridTile * sizeX, this->gridTile * sizeY));
  rect.setPosition(posX * this->gridTile, posY * this->gridTile);
  rect.setFillColor(color);
  this->window->draw(rect);
}

void Draw::drawRectangleWithOutline(float posX, float posY, float sizeX, float sizeY, sf::Color &color)
{
  sf::RectangleShape rect(sf::Vector2f(this->gridTile * sizeX, this->gridTile * sizeY));
  rect.setPosition(posX * this->gridTile, posY * this->gridTile);
  rect.setFillColor(color);
  rect.setOutlineColor(sf::Color(0, 0, 0));
  rect.setOutlineThickness(this->gridTile / 20);
  this->window->draw(rect);
}

void Draw::drawButton(string text, float posX, float posY, float sizeX, float sizeY, float textSize)
{
  sf::RectangleShape background(sf::Vector2f(sizeX * gridTile, sizeY * gridTile));
  background.setFillColor(theme->getButton());
  background.setPosition(sf::Vector2f(posX * gridTile, posY * gridTile));
  this->window->draw(background);

  sf::Text textNode(text, theme->getFont());
  textNode.setFillColor(sf::Color::White);
  textNode.setCharacterSize(textSize);

  sf::FloatRect textContainer = textNode.getLocalBounds();
  textNode.setOrigin(textContainer.left + textContainer.width / 2.0f, textContainer.top + textContainer.height / 2.0f);
  textNode.setPosition(sf::Vector2f(posX * gridTile + sizeX * gridTile / 2.0f, posY * gridTile + sizeY * gridTile / 2.0f));
  this->window->draw(textNode);
}

void Draw::endGame(Game &game)
{
  game.draw(this->windowSize, this->segments, this->window, *(this->theme));
  this->drawRectangleWithOutline(6, 4, 18, 22, this->theme->getPrimary());
  this->drawButton("Game Over!", 8, 6, 14, 3, this->gridTile);
  this->drawButton("Money: +" + to_string(game.getScore()), 8, 11, 14, 3, this->gridTile);
  this->drawButton("Restart!", 8, 16, 14, 3, this->gridTile);
  this->drawButton("Main Menu!", 8, 21, 14, 3, this->gridTile);
}

void Draw::mainMenu()
{
  this->drawButton("Start Game!", 6, 12, 18, 4, this->gridTile);
  this->drawButton("Store!", 6, 18, 18, 4, this->gridTile);
  this->drawButton("Exit!", 6, 24, 18, 4, this->gridTile);
}

void Draw::store(Store &storeRef, int money)
{
  for (int i = 0; i < storeRef.getItems().size(); i++)
  {
    this->drawRectangleWithOutline(3 + 9 * i, 5, 6, 6, storeRef.getSelectedProduct().getPrimary());
    for (int y = 0; y < 6; y++)
    {
      for (int x = 0; x < 6; x++)
      {
        int posX = 3 + x + 9 * i;
        int posY = 5 + y;
        sf::RectangleShape tile(sf::Vector2f(this->gridTile, this->gridTile));
        if ((posY % 2 == 1 && posX % 2 == 0) || (posY % 2 == 0 && posX % 2 == 1))
          tile.setFillColor(this->theme->getPrimary());
        else
          tile.setFillColor(this->theme->getSecondary());
        tile.setPosition(posX * this->gridTile, posY * this->gridTile);
        this->window->draw(tile);
      }
    }
    int posX = 3 + 9 * i;
    int posY = 5;

    sf::RectangleShape head(sf::Vector2f(this->gridTile, this->gridTile));
    head.setFillColor(this->theme->getSnakeHead());
    head.setPosition((posX + 4) * this->gridTile, (posY + 3) * this->gridTile);
    this->window->draw(head);

    sf::RectangleShape food(sf::Vector2f(this->gridTile, this->gridTile));
    food.setFillColor(this->theme->getFood());
    food.setPosition((posX + 2) * this->gridTile, (posY + 2) * this->gridTile);
    this->window->draw(food);

    for (int j = 0; j < 3; j++)
    {
      sf::RectangleShape tail(sf::Vector2f(this->gridTile, this->gridTile));
      tail.setFillColor(theme->getSnakeBody());
      tail.setPosition((posX + 2 + j) * this->gridTile, (posY + 4) * this->gridTile);
      this->window->draw(tail);
    }

    string buttonText = storeRef.getItem(i).getOwnership() ? "Select!" : "Buy: " + to_string(storeRef.getItem(i).getPrice());
    this->drawButton(buttonText, (3 + 9 * i), 13, 6, 3, this->gridTile / 2);
  }
  this->drawButton("Money: " + to_string(money), 6, 18, 18, 4, this->gridTile);
  this->drawButton("Go back!", 6, 24, 18, 4, this->gridTile);
}

void Draw::difficultyMenu()
{
  this->drawButton("Easy!", 6, 6, 18, 4, this->gridTile);
  this->drawButton("Medium!", 6, 12, 18, 4, this->gridTile);
  this->drawButton("Hard!", 6, 18, 18, 4, this->gridTile);
  this->drawButton("Extreme!", 6, 24, 18, 4, this->gridTile);
}

void Draw::game(Game &gameRef)
{
  gameRef.draw(this->windowSize, this->segments, this->window, *(this->theme));
  if (gameRef.getPaused())
  {
    this->drawRectangleWithOutline(6, 9, 18, 12, this->theme->getPrimary());
    this->drawButton("Continue!", 8, 11, 14, 3, this->gridTile);
    this->drawButton("Main Menu!", 8, 16, 14, 3, this->gridTile);
  }
}

void Draw::background()
{
  for (int y = 0; y < this->segments; y++)
  {
    for (int x = 0; x < this->segments; x++)
    {
      sf::RectangleShape tile(sf::Vector2f(this->gridTile, this->gridTile));
      if ((y % 2 == 1 && x % 2 == 0) || (y % 2 == 0 && x % 2 == 1))
        tile.setFillColor(this->theme->getPrimary());
      else
        tile.setFillColor(this->theme->getSecondary());
      tile.setPosition(x * this->gridTile, y * this->gridTile);
      this->window->draw(tile);
    }
  }
}