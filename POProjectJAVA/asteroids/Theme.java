package asteroids;

import java.awt.Font;
import java.awt.Color;

public class Theme {
  private Color backgroundColor;
  private Color menuColor;
  private Color buttonColor;
  private Color shipColor;
  private Color asteroidColor;
  private Color asteroidOutline;
  private Font font;
  private Color fontColor;

  public Theme() {
    backgroundColor = new Color(0, 0, 0);
    menuColor = new Color(37, 55, 69);
    buttonColor = new Color(32, 44, 57);
    shipColor = new Color(255, 255, 255);
    asteroidColor = new Color(255, 255, 255);
    asteroidOutline = new Color(255, 255, 255);
    font = new Font("Bold", 1, 20);
    fontColor = new Color(255, 255, 255);
  }

  public Color getBackgroundColor() {
    return this.backgroundColor;
  }

  public Color getMenuColor() {
    return this.menuColor;
  }

  public Color getButtonColor() {
    return this.buttonColor;
  }

  public Color getShipColor() {
    return this.shipColor;
  }

  public Color getAsteroidColor() {
    return this.asteroidColor;
  }

  public Color getAsteroidOutline() {
    return this.asteroidOutline;
  }

  public Font getFont() {
    return this.font;
  }

  public Color getFontColor() {
    return this.fontColor;
  }
}
