#include "Store.h"

/*
 _____ _____ _   _  _____ ___________ _   _ _____ _____ ___________  _____ 
/  __ \  _  | \ | |/  ___|_   _| ___ \ | | /  __ \_   _|  _  | ___ \/  ___|
| /  \/ | | |  \| |\ `--.  | | | |_/ / | | | /  \/ | | | | | | |_/ /\ `--. 
| |   | | | | . ` | `--. \ | | |    /| | | | |     | | | | | |    /  `--. \
| \__/\ \_/ / |\  |/\__/ / | | | |\ \| |_| | \__/\ | | \ \_/ / |\ \ /\__/ /
 \____/\___/\_| \_/\____/  \_/ \_| \_|\___/ \____/ \_/  \___/\_| \_|\____/ 
                                                                           
*/

Store::Store()
{
  this->items = vector<StoreItem>();
  this->loadStock();
  this->selectedItem = 0;
}

/*
 _____  _____ _____ _____ ___________  _____            _____ _____ _____ _____ ___________  _____ 
|  __ \|  ___|_   _|_   _|  ___| ___ \/  ___|   ___    /  ___|  ___|_   _|_   _|  ___| ___ \/  ___|
| |  \/| |__   | |   | | | |__ | |_/ /\ `--.   ( _ )   \ `--.| |__   | |   | | | |__ | |_/ /\ `--. 
| | __ |  __|  | |   | | |  __||    /  `--. \  / _ \/\  `--. \  __|  | |   | | |  __||    /  `--. \
| |_\ \| |___  | |   | | | |___| |\ \ /\__/ / | (_>  < /\__/ / |___  | |   | | | |___| |\ \ /\__/ /
 \____/\____/  \_/   \_/ \____/\_| \_|\____/   \___/\/ \____/\____/  \_/   \_/ \____/\_| \_|\____/ 
    
*/

vector<StoreItem> &Store::getItems()
{
  return this->items;
}

StoreItem &Store::getItem(int index)
{
  return this->items[index];
}

void Store::loadStock()
{
  this->items = vector<StoreItem>();
  this->items.push_back(
      StoreItem(
          Theme(
              sf::Color(170, 215, 81),
              sf::Color(168, 209, 73),
              sf::Color(255, 0, 0),
              sf::Color(255, 180, 72),
              sf::Color(247, 170, 62),
              sf::Color(255, 180, 72)),
          0,
          true));
  this->items.push_back(
      StoreItem(
          Theme(
              sf::Color(255, 180, 72),
              sf::Color(247, 170, 62),
              sf::Color(255, 0, 0),
              sf::Color(37, 55, 69),
              sf::Color(32, 44, 57),
              sf::Color(37, 55, 69)),
          50,
          false));
  this->items.push_back(
      StoreItem(
          Theme(
              sf::Color(37, 55, 69),
              sf::Color(32, 44, 57),
              sf::Color(255, 0, 0),
              sf::Color(170, 215, 81),
              sf::Color(168, 209, 73),
              sf::Color(170, 215, 81)),
          100,
          false));
}

/*
 _     _____ _____ _____ _____ 
| |   |  _  |  __ \_   _/  __ \
| |   | | | | |  \/ | | | /  \/
| |   | | | | | __  | | | |    
| |___\ \_/ / |_\ \_| |_| \__/\
\_____/\___/ \____/\___/ \____/
      
*/

void Store::selectItem(int index, int &money)
{
  if (index >= 0 && index <= this->items.size())
  {
    StoreItem &wanted = this->getItem(index);
    if (wanted.getOwnership())
      this->selectedItem = index;
    else if (this->getItem(index).getPrice() <= money)
    {
      this->buy(index, money);
      this->selectedItem = index;
    }
  }
}

void Store::buy(int index, int &money)
{
  money -= this->getItem(index).getPrice();
  this->getItem(index).setOwnership(true);
}

Theme &Store::getSelectedProduct()
{
  return this->getItem(this->selectedItem).getItem();
}