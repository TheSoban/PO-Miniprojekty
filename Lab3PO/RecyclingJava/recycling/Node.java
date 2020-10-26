package recycling;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;
import java.util.Scanner;
import java.util.UUID;
import java.util.Comparator;

class NodeComparator implements Comparator<Node> {
  @Override
  public int compare(Node n1, Node n2) {
    return n1.id.compareTo(n2.id);
  }
}

public class Node {
  protected ArrayList<Node> connectionsAL;
  protected HashMap<Node, Boolean> connectionsHM;
  protected TreeMap<Node, Boolean> connectionsTM;
  protected String id;

  public Node() {
    this.connectionsAL = new ArrayList<Node>();
    this.connectionsHM = new HashMap<Node, Boolean>();
    this.connectionsTM = new TreeMap<Node, Boolean>(new NodeComparator());
    this.id = UUID.randomUUID().toString();
  }

  protected void addConnection(Node node) {
    this.connectionsAL.add(node);
    this.connectionsHM.put(node, true);
    this.connectionsTM.put(node, true);
  }

  @Deprecated
  @Override
  protected void finalize() throws Throwable {
    System.out.println("Finalising object");
    super.finalize();
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    for (int i = 0; i <= 1000000; i++) {
      Node n1 = new Node();
      Node n2 = new Node();
      n1.addConnection(n2);
      n2.addConnection(n1);
    }
    s.nextLine();
    s.close();

    // Zadanie 7
    // Przy 10000 iteracji program nie wypisuje żadnego tekstu
    // Przy 1000000 iteracji program niejednokrotnie wypisze komunikat 'Finalising object'.
    // Metoda finalize jest nieprzewidywalna i nigdy nie wiadomo czy zostanie uruchomiona przez garbage collector.
    // Nie należy w niej uruchamiać ważnego kodu, przy większej ilości iteracji jest większa szansa na jej uruchomienie.

    // Zadanie 11
    // Dostęp do zmiennych jest możliwy jedynie wewnątrz funkcji for, kolejna iteracja sprawia, iż definiujemy nowe obiekty.
    // Stare obiekty o tych samych nazwach są usuwane przez garbage collector.

    // Zadanie 12
    // Tradycyjna tablica ma określony rozmiar i nie jest dla niej dostępna realokacja rozmiaru pamięci.
    // Typ ArrayList ma wbudowaną automatyczną realokację pamięci gdy tylko nastąpi taka potrzeba.
    // W sytuacji gdzie nie wiemy jak dużo połączeń będzie istniało między konkretnymi węzłami najlepiej użyć dynamicznego zbioru danych.
  }
}