package exceptions;

public class CustomerNotFoundException extends Exception {
  static final long serialVersionUID = 1l;
  private String name;

  public String getName() {
    return this.name;
  }

  CustomerNotFoundException() {
  }

  CustomerNotFoundException(String name) {
    super("Customer not found: " + name);
    this.name = name;
  }
}
