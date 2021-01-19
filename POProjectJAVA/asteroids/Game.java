package asteroids;

import java.util.ArrayList;
import java.awt.Graphics;

public class Game implements CanvasItem {
  private Ship player;
  private int score;
  private int difficulty;
  private int asteroidCooldown;
  private ArrayList<Asteroid> asteroids;

  public Game(Weapon weapon, int difficulty) {
    this.player = new Ship(weapon);
    this.score = 0;
    this.difficulty = difficulty;
    this.asteroids = new ArrayList<Asteroid>();
    this.asteroidCooldown = 200 / difficulty;
  }

  public boolean isOver() {
    for (Asteroid asteroid : this.asteroids) {
      if (asteroid.getPosition().distanceTo(this.player.getPosition()) <= asteroid.getRadius() + this.player.getSize())
        return true;
    }
    return false;
  }

  public int getScore() {
    return this.score;
  }

  public int getDifficulty() {
    return this.difficulty;
  }

  public void deleteOldEntities() {
    this.asteroids.removeIf(asteroid -> asteroid.getPosition().getX() < 0 || asteroid.getPosition().getX() > 100
        || asteroid.getPosition().getY() < 0 || asteroid.getPosition().getY() > 100);
    this.player.getProjectiles()
        .removeIf(projectile -> projectile.getPosition().getX() < 0 || projectile.getPosition().getX() > 100
            || projectile.getPosition().getY() < 0 || projectile.getPosition().getY() > 100);
  }

  public void createNewAsteroid() {
    double choice = Math.random();
    Vector position;
    if (choice < 0.25)
      position = new Vector(Math.floor(Math.random() * 100), 0);
    else if (choice < 0.5)
      position = new Vector(Math.floor(Math.random() * 100), 100);
    else if (choice < 0.75)
      position = new Vector(0, Math.floor(Math.random() * 100));
    else
      position = new Vector(100, Math.floor(Math.random() * 100));
    Vector direction = new Vector(100 - 2 * position.getX(), 100 - 2 * position.getY()).setMagnitude(0.5);
    this.asteroids.add(new Asteroid(position, direction, (int) Math.floor(Math.random() * 3)));
  }

  public void splitAsteroid(Asteroid old) {
    if (old.getLevel() >= 1) {
      this.asteroids
          .add(new Asteroid(old.getPosition().copy(), old.getDirection().copy().rotate(10), old.getLevel() - 1));
      this.asteroids
          .add(new Asteroid(old.getPosition().copy(), old.getDirection().copy().rotate(-10), old.getLevel() - 1));
      // int i = 0;
      // for (Asteroid asteroid: this.asteroids) {
      // System.out.println("Asteroid #" + ++i);
      // }
    }
  }

  public void updateEntities() {
    this.player.update();
    for (CanvasItem asteroid : this.asteroids) {
      asteroid.update();
    }
    for (CanvasItem projectile : this.player.getProjectiles()) {
      projectile.update();
    }
    for (int asteroidId = this.asteroids.size() - 1; asteroidId >= 0; asteroidId--) {
      for (int projectileId = this.player.getProjectiles().size() - 1; projectileId >= 0; projectileId--) {
        Projectile projectile = this.player.getProjectiles().get(projectileId);
        Asteroid asteroid = this.asteroids.get(asteroidId);
        if (projectile.getPosition().distanceTo(asteroid.getPosition()) <= projectile.getRadius()
            + asteroid.getRadius()) {
          asteroid.takeAHit(projectile);
          this.player.getProjectiles().remove(projectileId);
          if (asteroid.getHp() <= 0) {
            this.score += asteroid.getLevel();
            this.splitAsteroid(asteroid);
          }
        }
      }
    }
    for (int asteroidId = this.asteroids.size() - 1; asteroidId >= 0; asteroidId--) {
      if (this.asteroids.get(asteroidId).getHp() < 1) {
        this.splitAsteroid(this.asteroids.get(asteroidId));
        this.asteroids.remove(asteroidId);
      }
    }
  }

  public void handleInput(int keyCode, boolean change) {
    this.player.handleInput(keyCode, change);
  }

  public void update() {
    this.updateEntities();
    this.deleteOldEntities();
    if (--this.asteroidCooldown == 0) {
      this.asteroidCooldown = 200 / this.difficulty;
      createNewAsteroid();
    }
  }

  public void draw(Graphics g, Theme theme, int windowSize, int gridTile) {
    g.setColor(theme.getBackgroundColor());
    g.fillRect(0, 0, windowSize, windowSize);
    this.player.draw(g, theme, windowSize, gridTile);
    for (CanvasItem asteroid : this.asteroids) {
      asteroid.draw(g, theme, windowSize, gridTile);
    }
    for (CanvasItem projectile : this.player.getProjectiles()) {
      projectile.draw(g, theme, windowSize, gridTile);
    }
  }
}
