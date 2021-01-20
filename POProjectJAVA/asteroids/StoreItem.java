package asteroids;

public class StoreItem {
  private Weapon weapon;
  private int price;
  private boolean owned;

  public StoreItem(Weapon weapon, int price, boolean owned) {
    this.weapon = weapon;
    this.price = price;
    this.owned = owned;
  }

  public int getPrice() {
    return this.price;
  }

  public Weapon getWeapon() {
    return this.weapon;
  }

  public boolean getOwnership() {
    return this.owned;
  }

  public void setOwnership(boolean ownership) {
    this.owned = ownership;
  }
}
