package asteroids;

import java.awt.Graphics;
import java.util.ArrayList;
import java.awt.event.KeyEvent;

public class Ship implements CanvasItem {
  private Vector position;
  private Vector direction;
  private Weapon weapon;
  private double size;
  private double maxSpeed;
  private double currentSpeed;
  private double accelerationSpeed;
  private double decelerationSpeed;
  private double turningSpeed;
  private boolean accelerating;
  private boolean shooting;
  private boolean decelerating;
  private boolean turningRight;
  private boolean turningLeft;
  private int shootingCooldown;
  private ArrayList<Projectile> projectiles;

  public Ship(Weapon weapon) {
    this.position = new Vector(50, 50);
    this.direction = new Vector(1, 0);
    this.weapon = weapon;
    this.size = 3;
    this.maxSpeed = 0.8f;
    this.currentSpeed = 0;
    this.accelerationSpeed = 0.02f;
    this.decelerationSpeed = 0.015f;
    this.turningSpeed = 5;
    this.accelerating = false;
    this.decelerating = false;
    this.turningRight = false;
    this.turningLeft = false;
    this.shooting = false;
    this.shootingCooldown = 30 / this.weapon.getShotSpeed();
    this.projectiles = new ArrayList<Projectile>();
  }

  public ArrayList<Projectile> getProjectiles() {
    return this.projectiles;
  }

  public Vector getPosition() {
    return this.position;
  }

  public double getSize() {
    return this.size;
  }

  public void handleInput(int keyCode, boolean change) {
    if (keyCode == KeyEvent.VK_W)
      this.accelerating = change;
    if (keyCode == KeyEvent.VK_S)
      this.decelerating = change;
    if (keyCode == KeyEvent.VK_A)
      this.turningLeft = change;
    if (keyCode == KeyEvent.VK_D)
      this.turningRight = change;
    if (keyCode == KeyEvent.VK_SPACE)
      this.shooting = change;
  }

  public void update() {
    if (this.accelerating)
      this.currentSpeed = Math.min(this.currentSpeed + this.accelerationSpeed, this.maxSpeed);
    if (this.decelerating)
      this.currentSpeed = Math.max(this.currentSpeed - this.decelerationSpeed, 0);
    if (this.turningLeft)
      this.direction.rotate(-this.turningSpeed);
    if (this.turningRight)
      this.direction.rotate(this.turningSpeed);
    if (this.currentSpeed > 0)
      this.position.add(this.direction.copy().setMagnitude(this.currentSpeed));
    if (this.position.getX() < 0)
      this.position.setX(this.position.getX() + 100);
    if (this.position.getY() < 0)
      this.position.setY(this.position.getY() + 100);
    if (this.position.getX() > 100)
      this.position.setX(this.position.getX() - 100);
    if (this.position.getY() > 100)
      this.position.setY(this.position.getY() - 100);
    if (this.shooting) {
      if (--this.shootingCooldown == 0) {
        this.shootingCooldown = 30 / this.weapon.getShotSpeed();
        this.projectiles.add(new Projectile(this.position.copy(), this.direction.copy().setMagnitude(1.5),
            this.weapon.getProjectileSize() / 2, this.weapon.getProjectileDamage()));
      }
    }
  }

  public void draw(Graphics g, Theme theme, int windowSize, int gridTile) {
    // Ship
    g.setColor(theme.getShipColor());
    Vector front = this.position.copy().add(this.direction.copy().setMagnitude(this.size))
        .fromPercentToWindowSize(windowSize);
    Vector left = this.position.copy().add(this.direction.copy().rotate(-120).setMagnitude(this.size / 2))
        .fromPercentToWindowSize(windowSize);
    Vector bottom = this.position.copy().fromPercentToWindowSize(windowSize);
    Vector right = this.position.copy().add(this.direction.copy().rotate(120).setMagnitude(this.size / 2))
        .fromPercentToWindowSize(windowSize);
    int xPoints[] = { (int) front.getX(), (int) left.getX(), (int) bottom.getX(), (int) right.getX() };
    int yPoints[] = { (int) front.getY(), (int) left.getY(), (int) bottom.getY(), (int) right.getY() };
    g.fillPolygon(xPoints, yPoints, 4);

    // Engine
    if (this.accelerating) {
      Vector leftEngine = this.position.copy().add(this.direction.copy().rotate(-90).setMagnitude(this.size / 4))
          .fromPercentToWindowSize(windowSize);
      Vector rightEngine = this.position.copy().add(this.direction.copy().rotate(90).setMagnitude(this.size / 4))
          .fromPercentToWindowSize(windowSize);
      Vector bottomEngine = this.position.copy().add(this.direction.copy().rotate(180).setMagnitude(this.size / 1.5))
          .fromPercentToWindowSize(windowSize);
      int xPointsEngine[] = { (int) leftEngine.getX(), (int) rightEngine.getX(), (int) bottomEngine.getX() };
      int yPointsEngine[] = { (int) leftEngine.getY(), (int) rightEngine.getY(), (int) bottomEngine.getY() };
      g.fillPolygon(xPointsEngine, yPointsEngine, 3);
    }
  }
}
