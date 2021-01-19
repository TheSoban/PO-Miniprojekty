package exceptions;

public class Customer {
  private String name;
  private String address;

  public Customer() {
  }

  public Customer(String name, String address) {
    this.name = name;
    this.address = address;
  }

  public String getName() {
    return this.name;
  }

  public String getAddress() {
    return this.address;
  }

  @Override // Oznacza, ze nadpisujemy metode zadeklarowana na typie, z ktorego
            // dziedziczymy.
  public boolean equals(Object c) {
    return this.name.equals(((Customer) c).name);
  }
}