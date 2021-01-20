package asteroids;

import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferStrategy;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;

class Menu extends Canvas implements Runnable, MouseListener, KeyListener {
  private static final long serialVersionUID = 1L;
  private String name;
  private boolean running;
  private int windowSize;
  private int segments;
  private int money;
  private int framerate;
  private Theme theme;
  private String tab;
  private Game game;
  private Store store;
  private JFrame window;
  private int gridTile;
  private Draw draw;

  public Menu() {
    this.name = "Asteroids";
    this.running = true;
    this.tab = "mainMenu";
    this.windowSize = 900;
    this.segments = 30;
    this.gridTile = this.windowSize / this.segments;
    this.money = 70;
    this.framerate = 60;
    this.window = new JFrame(this.name);
    this.store = new Store();
    this.game = new Game(this.store.getCurrentItem(), 2);
    this.theme = new Theme();
    this.draw = new Draw(this.theme, this.windowSize, this.gridTile);
    this.window.addMouseListener(this);
    setMinimumSize(new Dimension(this.windowSize, this.windowSize));
    setMaximumSize(new Dimension(this.windowSize, this.windowSize));
    setPreferredSize(new Dimension(this.windowSize, this.windowSize));
    addMouseListener(this);
    addKeyListener(this);

    this.window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    this.window.add(this);
    this.window.pack();

    this.window.setResizable(false);
    this.window.setLocationRelativeTo(null);
    this.window.setVisible(true);
  }

  public synchronized void start() {
    this.running = true;
    new Thread(this).start();
  }

  public synchronized void stop() {
    this.running = false;
    this.window.dispatchEvent(new WindowEvent(this.window, WindowEvent.WINDOW_CLOSING));
  }

  void startNewGame(int difficulty) {
    this.game = new Game(this.store.getCurrentItem(), difficulty);
    this.tab = "game";
  }

  public void run() {
    long lastTime = System.nanoTime();
    double delta = 0;

    while (running) {
      long now = System.nanoTime();
      delta += (now - lastTime) / (1000000000D / (double) this.framerate);
      lastTime = now;
      boolean gameFrame = false;
      while (delta >= 1) {
        delta -= 1;
        gameFrame = true;
      }
      if (gameFrame) {
        this.update();
        this.draw();
      }
    }
  }

  public void update() {
    if (this.tab == "game") {
      this.game.update();
      if (this.game.isOver()) {
        this.money += game.getScore();
        this.tab = "endGame";
      }
    }
  }

  public void draw() {
    BufferStrategy bs = getBufferStrategy();
    if (bs == null) {
      createBufferStrategy(3);
      return;
    }
    Graphics g = bs.getDrawGraphics();
    if (this.tab == "mainMenu")
      this.draw.mainMenu(g);
    else if (this.tab == "difficultyMenu")
      this.draw.difficultyMenu(g);
    else if (this.tab == "game")
      this.draw.game(g, this.game);
    else if (this.tab == "endGame")
      this.draw.endGame(g, this.game);
    else if (this.tab == "store")
      this.draw.store(g, this.store, this.money);
    g.dispose();
    bs.show();
  }

  public void handleMouseInput(int x, int y) {
    if (this.tab == "mainMenu") {
      if (x >= 6 && x <= 24 && y >= 12 && y <= 16)
        this.tab = "difficultyMenu";
      if (x >= 6 && x <= 24 && y >= 18 && y <= 22)
        this.tab = "store";
      if (x >= 6 && x <= 24 && y >= 24 && y <= 28)
        this.stop();
    }

    else if (this.tab == "difficultyMenu") {
      if (x >= 6 && x <= 24 && y >= 6 && y <= 10)
        this.startNewGame(1);
      if (x >= 6 && x <= 24 && y >= 12 && y <= 16)
        this.startNewGame(2);
      if (x >= 6 && x <= 24 && y >= 18 && y <= 22)
        this.startNewGame(3);
      if (x >= 6 && x <= 24 && y >= 24 && y <= 28)
        this.startNewGame(4);
    }

    else if (this.tab == "endGame") {
      if (x >= 8 && x <= 22 && y >= 16 && y <= 19)
        this.startNewGame(this.game.getDifficulty());
      if (x >= 8 && x <= 22 && y >= 21 && y <= 24)
        this.tab = "mainMenu";
    }

    else if (this.tab == "store") {
      if (x >= 6 && x <= 24 && y >= 24 && y <= 28)
        this.tab = "mainMenu";
      else if (x >= 3 && x <= 9 && y >= 13 && y <= 16)
        this.money -= this.store.selectItem(0, this.money);
      else if (x >= 12 && x <= 18 && y >= 13 && y <= 16)
        this.money -= this.store.selectItem(1, this.money);
      else if (x >= 21 && x <= 27 && y >= 13 && y <= 16)
        this.money -= this.store.selectItem(2, this.money);
    }

    else if (this.tab == "game" && this.game.getPaused()) {
      if (x >= 8 && x <= 22 && y >= 11 && y <= 14)
        this.game.setPaused(false);
      if (x >= 8 && x <= 22 && y >= 16 && y <= 19)
        this.tab = "mainMenu";
    }
  }

  @Override
  public void mouseClicked(MouseEvent e) {
    int x = e.getX();
    int y = e.getY();
    this.handleMouseInput(x / this.gridTile, y / this.gridTile);
  }

  @Override
  public void mouseExited(MouseEvent e) {
  }

  @Override
  public void mouseEntered(MouseEvent e) {
  }

  @Override
  public void mouseReleased(MouseEvent e) {
  }

  @Override
  public void mousePressed(MouseEvent e) {
  }

  @Override
  public void keyTyped(KeyEvent e) {

  }

  @Override
  public void keyPressed(KeyEvent e) {
    this.game.handleInput(e.getKeyCode(), true);
  }

  @Override
  public void keyReleased(KeyEvent e) {
    this.game.handleInput(e.getKeyCode(), false);
  }

  public static void main(String args[]) {
    Menu menu = new Menu();
    menu.run();
  }
}
