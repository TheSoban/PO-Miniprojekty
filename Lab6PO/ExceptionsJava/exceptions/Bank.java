package exceptions;

import java.util.ArrayList;

public class Bank implements SearchAccounts, SearchCustomers {
  private ArrayList<Customer> customers = new ArrayList<Customer>();
  private ArrayList<Account> accounts = new ArrayList<Account>();

  @Override
  public Customer findByName(String name) throws CustomerNotFoundException {
    for (Customer customer : this.customers) {
      if (customer.getName().equals(name))
        return customer;
    }
    throw new CustomerNotFoundException(name);
  }

  @Override
  public Account findByNumber(int num) throws AccountNotFoundException {
    for (Account account : this.accounts) {
      if (account.getNumber() == num)
        return account;
    }
    throw new AccountNotFoundException(num);
  }

  @Override
  public ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException {
    ArrayList<Account> accounts = new ArrayList<Account>();
    for (Account account : this.accounts) {
      if (account.getCustomer() == cust)
        accounts.add(account);
    }
    if (accounts.size() > 0)
      return accounts;
    throw new AccountNotFoundException(cust);

  }

  public void addNewCustomer(String name, String address) {
    this.customers.add(new Customer(name, address));
  }

  public void addNewAccount(int n, Customer c, int p, String l) {
    this.accounts.add(new Account(n, c, p, l));
  }

  public Customer getCustomer(int index) {
    return this.customers.get(index);
  }

  public Account getAccount(int index) {
    return this.accounts.get(index);
  }

  public void printCustomer(String name) {
    System.out.println("Customer by the name '" + name + "'");
    try {
      Customer found = this.findByName(name);
      System.out.println("Name: " + found.getName());
      System.out.println("Address: " + found.getAddress());
    } catch (CustomerNotFoundException e) {
      System.out.println(e.getMessage());
      e.printStackTrace();
      e.fillInStackTrace();
      e.printStackTrace();
    }
  }

  public void printAccount(int num) {
    System.out.println("Account by the number '" + num + "'");
    try {
      Account found = this.findByNumber(num);
      System.out.println("Number: " + found.getNumber());
      System.out.println("Owner: " + found.getCustomer().getName());
      System.out.println("Balance: " + found.getBalance());
      System.out.println("Login: " + found.getLogin());
    } catch (AccountNotFoundException e) {
      e.printStackTrace();
    }
  }

  public void printAllCustomerAccounts(Customer cust) {
    System.out.println("All accounts by the customer '" + cust.getName() + " - " + cust.getAddress() + "'");
    try {
      for (Account account : this.findAllCustomerAccounts(cust)) {
        this.printAccount(account.getNumber());
      }
    } catch (AccountNotFoundException e) {
      e.printStackTrace();
    }
  }

  public void printAccountLogin(Account acc, String log, int pass) {
    System.out.println("Account data after login: '" + acc.getNumber() + "'");
    try {
      acc.login(log, pass);
      System.out.println("Balance: '" + acc.getBalance() + "'");
    } catch (AccountLoginFailedException e) {
      e.printStackTrace();
    }
  }

  public static void main(String[] args) {
    // Zadanie 9
    // Interfejsy pozwalaja na zdefiniowanie metod potrzebnych w danej klasie, java
    // pozwala takze na rozszerzanie wielu interfejsow,
    // co nie jest mozliwe dla dziedziczenia z wielu klas

    // Zadanie 10

    // Osobno
    // Bank bank = new Bank();
    // bank.addNewCustomer("Kowalski", "Poznan");
    // bank.addNewCustomer("Nowak", "Warszawa");
    // bank.addNewAccount(123, bank.getCustomer(0), 456, "Kowalski12");
    // bank.addNewAccount(124, bank.getCustomer(0), 456, "Kowalski12");
    // bank.addNewAccount(225, bank.getCustomer(1), 789, "Nowak22");
    // bank.addNewAccount(226, bank.getCustomer(1), 789, "Nowak22");
    // System.out.println("------------------------------");
    // bank.printCustomer("Kowalski");
    // System.out.println("------------------------------");
    // bank.printCustomer("Kot");
    // System.out.println("------------------------------");
    // bank.printAccount(123);
    // System.out.println("------------------------------");
    // bank.printAccount(125);
    // System.out.println("------------------------------");
    // bank.printAllCustomerAccounts(bank.getCustomer(0));
    // System.out.println("------------------------------");
    // bank.printAllCustomerAccounts(new Customer("Pies", "Gdansk"));
    // System.out.println("------------------------------");
    // bank.printAccountLogin(bank.getAccount(0), "Kowalski12", 456);
    // System.out.println("------------------------------");
    // bank.printAccountLogin(bank.getAccount(0), "Kowalski12", 222);
    // System.out.println("------------------------------");

    // Razem
    // Bank bank2 = new Bank();
    // bank2.addNewCustomer("Kowalski", "Poznan");
    // bank2.addNewAccount(123, bank2.getCustomer(0), 456, "Kowalski12");

    // try {
    // bank2.getAccount(0).login("Kowalski12", 456);
    // bank2.findAllCustomerAccounts(bank2.getCustomer(0));
    // bank2.findByName("Kowalski");
    // bank2.findByNumber(123);
    // } catch (AccountLoginFailedException e) {
    // System.out.println(e.getMessage());
    // } catch (AccountNotFoundException e) {
    // System.out.println(e.getMessage());
    // } catch (CustomerNotFoundException e) {
    // System.out.println(e.getMessage());
    // }

    // Bank bank3 = new Bank();
    // bank3.printCustomer("Kowalski");

    // Zadanie 11
    // Slady stosu sa identyczne

    // Zadanie 12
    // Slady stosu roznia sie gdyz fillInStackTrace zmienia zawartosc stack trace na
    // odpowiadajacy miejscu wykonania metody fillInStackTrace
    // omija w tym przypadku wykonanie metody findByName.

  }

}
