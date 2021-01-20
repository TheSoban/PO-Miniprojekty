package asteroids;

public class Weapon {
  private int projectileSize;
  private int shotSpeed;
  private int projectileDamage;

  public Weapon(int projectileSize, int shotSpeed, int projectileDamage) {
    this.projectileSize = projectileSize;
    this.shotSpeed = shotSpeed;
    this.projectileDamage = projectileDamage;
  }

  public int getProjectileSize() {
    return this.projectileSize;
  }

  public int getShotSpeed() {
    return this.shotSpeed;
  }

  public int getProjectileDamage() {
    return this.projectileDamage;
  }
}
