package exceptions;

public interface SearchCustomers {
  Customer findByName(String name) throws CustomerNotFoundException;
}
