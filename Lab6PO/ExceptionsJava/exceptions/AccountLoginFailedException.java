package exceptions;

public class AccountLoginFailedException extends Exception {
  static final long serialVersionUID = 1L;
  private int password;
  private String login;
  private Customer owner;

  AccountLoginFailedException() {
  }

  AccountLoginFailedException(String errorMsg, Customer c, int p, String l) {
    super(errorMsg);
    this.owner = c;
    this.password = p;
    this.login = l;
  }

  public int getPassword() {
    return this.password;
  }

  public Customer getCustomer() {
    return this.owner;
  }

  public String getLogin() {
    return this.login;
  }

}
