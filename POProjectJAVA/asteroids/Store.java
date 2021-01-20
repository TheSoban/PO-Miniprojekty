package asteroids;

public class Store {
  private StoreItem items[] = new StoreItem[3];
  private int currentItem;

  public Store() {
    this.items[0] = new StoreItem(new Weapon(3, 3, 1), 0, true);
    this.items[1] = new StoreItem(new Weapon(2, 4, 1), 50, false);
    this.items[2] = new StoreItem(new Weapon(5, 2, 2), 100, false);
    this.currentItem = 0;
  }

  public Weapon getCurrentItem() {
    return this.items[this.currentItem].getWeapon();
  }

  public StoreItem[] getItems() {
    return this.items;
  }

  public StoreItem getItem(int index) {
    return this.items[index];
  }

  public int selectItem(int index, int money) {
    if (index >= 0 && index < 3) {
      if (this.items[index].getOwnership()) {
        this.currentItem = index;
      } else if (this.items[index].getPrice() <= money) {
        this.items[index].setOwnership(true);
        this.currentItem = index;
        return this.items[index].getPrice();
      }
    }
    return 0;
  }
}
