#ifndef STOREITEM_H
#define STOREITEM_H
#include <SFML/Graphics.hpp>
#include "Theme.h"

using namespace std;

class StoreItem
{
private:
  Theme item;
  int price;
  bool owned;

public:
  StoreItem(Theme item, int price, bool owned);
  int getPrice();
  Theme &getItem();
  bool getOwnership();
  void setOwnership(bool ownership);
};

#endif