package exceptions;

public class Account {
  private int accountNumber;
  private Customer owner;
  private double balance;
  private int password;
  private String login;

  public Account() {
  }

  public Account(int n, Customer c, int p, String l) {
    this.accountNumber = n;
    this.owner = c;
    this.balance = 0;
    this.password = p;
    this.login = l;
  }

  public void login(String l, int passwd) throws AccountLoginFailedException {
    if (l != this.login || passwd != this.password)
      throw new AccountLoginFailedException("Invalid Login Information", this.owner, passwd, l);
  }

  public Customer getCustomer() {
    return this.owner;
  }

  public int getNumber() {
    return this.accountNumber;
  }

  public double getBalance() {
    return this.balance;
  }

  public String getLogin() {
    return this.login;
  }

  public double withdraw(double amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      return this.balance;
    } else {
      System.out.println("Withdraw rejected.");
      return this.balance;
    }
  }
}