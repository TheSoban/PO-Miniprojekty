package asteroids;

import java.awt.Graphics;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Color;

public class Draw {
  private Theme theme;
  private int windowSize;
  private int gridTile;

  public Draw(Theme theme, int windowSize, int gridTile) {
    this.theme = theme;
    this.windowSize = windowSize;
    this.gridTile = gridTile;
  }

  public void drawText(Graphics g, String text, int posX, int posY, int sizeX, int sizeY) {
    Font font = this.theme.getFont();
    FontMetrics metrics = g.getFontMetrics(font);
    int x = (posX * this.gridTile) + ((sizeX * this.gridTile) - metrics.stringWidth(text)) / 2;
    int y = (posY * this.gridTile) + (((sizeY * this.gridTile) - metrics.getHeight()) / 2) + metrics.getAscent();
    g.setFont(font);
    g.setColor(this.theme.getFontColor());
    g.drawString(text, x, y);
  }

  public void drawRectangle(Graphics g, int posX, int posY, int sizeX, int sizeY, Color color) {
    g.setColor(color);
    g.fillRect(posX * this.gridTile, posY * this.gridTile, sizeX * this.gridTile, sizeY * this.gridTile);
  }

  public void drawMenuBackground(Graphics g) {
    this.drawRectangle(g, 0, 0, this.windowSize / this.gridTile, this.windowSize / this.gridTile,
        this.theme.getMenuColor());
  }

  public void drawButton(Graphics g, String text, int posX, int posY, int sizeX, int sizeY) {
    this.drawRectangle(g, posX, posY, sizeX, sizeY, this.theme.getButtonColor());
    this.drawText(g, text, posX, posY, sizeX, sizeY);
  }

  public void mainMenu(Graphics g) {
    this.drawMenuBackground(g);
    this.drawButton(g, "Start Game!", 6, 12, 18, 4);
    this.drawButton(g, "Store!", 6, 18, 18, 4);
    this.drawButton(g, "Exit!", 6, 24, 18, 4);
  }

  public void difficultyMenu(Graphics g) {
    this.drawMenuBackground(g);
    this.drawButton(g, "Easy!", 6, 6, 18, 4);
    this.drawButton(g, "Medium!", 6, 12, 18, 4);
    this.drawButton(g, "Hard!", 6, 18, 18, 4);
    this.drawButton(g, "Extreme!", 6, 24, 18, 4);
  }

  public void game(Graphics g, CanvasItem game) {
    game.draw(g, this.theme, this.windowSize, this.gridTile);
  }

  public void endGame(Graphics g, Game game) {
    game.draw(g, this.theme, this.windowSize, this.gridTile);
    this.drawRectangle(g, 6, 4, 18, 22, this.theme.getMenuColor());
    this.drawButton(g, "Game Over!", 8, 6, 14, 3);
    this.drawButton(g, "Money: +" + game.getScore(), 8, 11, 14, 3);
    this.drawButton(g, "Restart!", 8, 16, 14, 3);
    this.drawButton(g, "Main Menu!", 8, 21, 14, 3);
  }

  public void store(Graphics g, Store store, int money) {
    this.drawMenuBackground(g);
    for (int i = 0; i < 3; i++) {
      this.drawRectangle(g, 2 + 9 * i, 5, 8, 5, theme.getButtonColor());
      this.drawButton(g, "Projectile size: " + store.getItem(i).getWeapon().getProjectileSize(), 2 + 9 * i, 6, 8, 1);
      this.drawButton(g, "Shot speed: " + store.getItem(i).getWeapon().getShotSpeed(), 2 + 9 * i, 7, 8, 1);
      this.drawButton(g, "Projectile damage: " + store.getItem(i).getWeapon().getProjectileDamage(), 2 + 9 * i, 8, 8,
          1);

      String buttonText = store.getItem(i).getOwnership() ? "Select!" : "Buy " + store.getItem(i).getPrice();
      buttonText = store.getItem(i).getWeapon() == store.getCurrentItem() ? "Selected!" : buttonText;
      this.drawButton(g, buttonText, 3 + 9 * i, 13, 6, 3);
    }
    this.drawButton(g, "Money: " + money, 6, 18, 18, 4);
    this.drawButton(g, "Go back!", 6, 24, 18, 4);
  }
}
