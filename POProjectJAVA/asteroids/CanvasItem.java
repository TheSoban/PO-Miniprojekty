package asteroids;

import java.awt.Graphics;

public interface CanvasItem {
  public void update();

  public void draw(Graphics g, Theme theme, int windowSize, int gridTile);
}
