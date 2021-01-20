package asteroids;

import java.awt.Graphics;

public class Asteroid implements CanvasItem {
  private Vector position;
  private Vector direction;
  private double radius;
  private int level;
  private int hp;

  public Asteroid(Vector position, Vector direction, int level) {
    this.position = position;
    this.direction = direction;
    this.level = level;
    this.radius = level * 3;
    this.hp = level;
  }

  public int getHp() {
    return this.hp;
  }

  public Vector getPosition() {
    return this.position;
  }

  public Vector getDirection() {
    return this.direction;
  }

  public double getRadius() {
    return this.radius;
  }

  public int getLevel() {
    return this.level;
  }

  public void takeAHit(Projectile projectile) {
    this.hp -= projectile.getDamage();
  }

  public void update() {
    this.position.add(this.direction);
  }

  public void draw(Graphics g, Theme theme, int windowSize, int gridTile) {
    g.setColor(theme.getAsteroidColor());
    Vector center = this.position.copy().add(new Vector(-this.radius, -this.radius))
        .fromPercentToWindowSize(windowSize);
    int x = (int) center.getX();
    int y = (int) center.getY();
    int radius = (int) (this.radius * windowSize / 100);
    g.fillOval(x, y, radius * 2, radius * 2);
  }
}
