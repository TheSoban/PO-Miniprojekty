package asteroids;

public class Vector {
  private double x;
  private double y;

  public Vector() {
    this.x = 0;
    this.y = 0;
  }

  public Vector(double x, double y) {
    this.x = x;
    this.y = y;
  }

  public double getX() {
    return this.x;
  }

  public double getY() {
    return this.y;
  }

  public Vector setX(double x) {
    this.x = x;
    return this;
  }

  public Vector setY(double y) {
    this.y = y;
    return this;
  }

  public Vector rotate(double degrees) {
    double px = this.x * Math.cos(Math.toRadians(degrees)) - this.y * Math.sin(Math.toRadians(degrees));
    double py = this.x * Math.sin(Math.toRadians(degrees)) + this.y * Math.cos(Math.toRadians(degrees));
    this.x = px;
    this.y = py;
    return this;
  }

  public Vector fromPercentToWindowSize(int windowSize) {
    return new Vector(this.x / 100 * windowSize, this.y / 100 * windowSize);
  }

  public Vector add(Vector other) {
    this.x += other.x;
    this.y += other.y;
    return this;
  }

  public Vector copy() {
    return new Vector(this.x, this.y);
  }

  public double getMagnitude() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
  }

  public Vector setMagnitude(double magnitude) {
    this.x = this.x * magnitude / this.getMagnitude();
    this.y = this.y * magnitude / this.getMagnitude();
    return this;
  }

  public double distanceTo(Vector other) {
    return Math.sqrt(Math.pow(other.x - this.x, 2) + Math.pow(other.y - this.y, 2));
  }
}
