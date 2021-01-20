package asteroids;

import java.awt.Graphics;

public class Projectile implements CanvasItem {
  private Vector position;
  private Vector direction;
  private double radius;
  private int damage;

  public Projectile(Vector position, Vector direction, double radius, int damage) {
    this.position = position;
    this.direction = direction;
    this.radius = radius;
    this.damage = damage;
  }

  public Vector getPosition() {
    return this.position;
  }

  public int getDamage() {
    return this.damage;
  }

  public double getRadius() {
    return this.radius;
  }

  public void update() {
    this.position.add(this.direction);
  }

  public void draw(Graphics g, Theme theme, int windowSize, int gridTile) {
    g.setColor(theme.getShipColor());
    Vector center = this.position.copy().add(new Vector(-this.radius, -this.radius))
        .fromPercentToWindowSize(windowSize);
    int x = (int) center.getX();
    int y = (int) center.getY();
    int radius = (int) (this.radius * windowSize / 100);
    g.fillOval(x, y, radius * 2, radius * 2);
  }
}
