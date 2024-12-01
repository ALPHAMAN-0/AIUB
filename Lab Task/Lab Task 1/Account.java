/*
 *         SIAM HOSSAIN
 *         ID 24-56637-1
 */

public class Account {

    // Declare attributes
    private int accountNumber;
    private String accountHolderName;
    private double balance;
    
    // Constructor
    public Account(int accountNumber, String accountHolderName, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }

    // Default constructor
    public Account() {
    }

    // Setter methods
    public void setAccountNumber(int an) {
        this.accountNumber = an;
    }

    public void setAccountHolderName(String ahn) {
        this.accountHolderName = ahn;
    }

    public void setBalance(double b) {
        this.balance = b;
    }

    // Getter methods
    public int getAccountNumber() {
        return accountNumber;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }

    public double getBalance() {
        return balance;
    }
    
    // Show Info
    public void showInfo() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Holder Name: " + accountHolderName);
        System.out.println("Balance: " + balance);
    }

    // Main method for testing purposes
    public static void main(String[] args) {
        // Create Object using parameterized constructor
        Account s1 = new Account(24566371, "Siam", 1000);
        s1.showInfo();

        // Create Object using default constructor
        Account s2 = new Account();
        s2.setAccountNumber(24566372);
        s2.setAccountHolderName("Hossain");
        s2.setBalance(2000);
        s2.showInfo();
    }
}
