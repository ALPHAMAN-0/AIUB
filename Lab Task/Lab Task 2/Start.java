/*
 *             SIAM HOSSAIN
 *             ID 24-56637-1
 */

class Book {

    //declare instance variable
    private String isbn;
    private String bookTitle;
    private String authorName;
    private double price;
    private int availableQuantity;
     
    Book(){
        //default constructor
        }
    

    Book(String isbn, String bookTitle, String authorName, double price, int availableQuantity){
         //parameterized constructor
         this.isbn = isbn;
         this.bookTitle = bookTitle;
         this.authorName = authorName;
         this.price = price;
         this.availableQuantity = availableQuantity;
    }

    //setter method
    public void setIsbn(String isbn){
        this.isbn = isbn;
    }
    public void setBookTitle(String bookTitle){
        this.bookTitle = bookTitle;
    }
    public void setAuthorName(String authorName){
        this.authorName = authorName;
    }
    public void setPrice(double price){
        this.price = price;
    }

    public void setAvailableQuantity(int availableQuantity){
        this.availableQuantity = availableQuantity;
    }

    //getter method
    public String getIsbn(){
        return isbn;
    }
    public String getBookTitle(){
        return bookTitle;
    }
    public String getAuthorName(){
        return authorName;
    }
    public double getPrice(){
        return price;
    }
    public int getAvailableQuantity(){
        return availableQuantity;
    }
    
    // adding Quantity
    public void addQuantity(int amount){
        if(amount>0){
            availableQuantity += amount;
        }
        else{
            System.out.println("Invalid Quantity");
        }
    }
     // selling Quantity
    public void sellQuantity(int amount){
        if(amount>0 && amount<=availableQuantity){
            availableQuantity -= amount;
        }
        else{
            System.out.println("Invalid Quantity");
        }
    }
    
    //show book details
    public void showDetails(){
        System.out.println("ISBN: "+isbn);
        System.out.println("Book Title: "+bookTitle);
        System.out.println("Author Name: "+authorName);
        System.out.println("Price: "+price);
        System.out.println("Available Quantity: "+availableQuantity);
        System.out.println();
    }
}
public class Start{
    public static void main(String[] args) {
        // Create a Book object using the parameterized constructor
        Book book1 = new Book("123-456-789", "Java Programming", "John Doe", 29.99, 10);
        book1.showDetails();

        // Add quantity
        book1.addQuantity(5);
        book1.showDetails();

        // Sell quantity
        book1.sellQuantity(3);
        book1.showDetails();

        // Create a Book object using the default constructor
        Book book2 = new Book();
        book2.setIsbn("987-654-321");
        book2.setBookTitle("Python Programming");
        book2.setAuthorName("Jane Doe");
        book2.setPrice(39.99);
        book2.setAvailableQuantity(15);
        book2.showDetails();
    }
}