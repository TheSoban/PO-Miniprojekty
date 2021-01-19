package exceptions;

public class AccountNotFoundException extends Exception {
  static final long serialVersionUID = 1l;
  private int num;
  private Customer cust;

  public int getNumber() {
    return this.num;
  }

  public Customer getCustomer() {
    return this.cust;
  }

  AccountNotFoundException() {
  }

  AccountNotFoundException(int num) {
    super("Account not found: " + num);
    this.num = num;
  }

  AccountNotFoundException(Customer cust) {
    super("Account not found: " + cust.getName() + " - " + cust.getAddress());
    this.cust = cust;
  }
}