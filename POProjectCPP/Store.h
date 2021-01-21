#ifndef STORE_H
#define STORE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "StoreItem.h"

using namespace std;

class Store
{
private:
  vector<StoreItem> items;
  int selectedItem;
  void buy(int index, int &money);
  void loadStock();

public:
  Store();
  vector<StoreItem> &getItems();
  StoreItem &getItem(int index);
  Theme &getSelectedProduct();
  void selectItem(int index, int &money);
};

#endif