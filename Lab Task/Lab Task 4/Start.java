/*
 *              SIAM HOSSAIN
 *              ID 24-56637-1
 */
class Book{
    private String isbn;
    private String bookTitle;
    private String authorName;
    private double price;
    private int availableQuantity;

    Book(){
        //default constructor
    }

    Book(String isbn, String bookTitle, String authorName, double price, int availableQuantity){
        this.isbn = isbn;
        this.bookTitle = bookTitle;
        this.authorName = authorName;
        this.price = price;
        this.availableQuantity = availableQuantity;
    }


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

    public void addQuantity(int amount){
        if(amount>0){
            availableQuantity += amount;
        }
        else{
            System.out.println("Invalid amount");
        }
    }

    public void sellQuantity(int amount){
        if(amount>0 && amount<=availableQuantity){
            availableQuantity -= amount;
        }
        else{
            System.out.println("Invalid amount");
        }
    }

    public void showDetails(){
        System.out.println("ISBN: "+isbn);
        System.out.println("Book Title: "+bookTitle);
        System.out.println("Author Name: "+authorName);
        System.out.println("Price: "+price);
        System.out.println("Available Quantity: "+availableQuantity);
    }
}
public class Start {
        public static void main(String[] args){
           Book[] books = new Book[3];
           
            books[0] = new Book("1234", "Java", "Siam", 500, 10);
            books[1] = new Book("5678", "Python", "Rohan", 600, 20);
            books[2] = new Book("9101", "C++", "Robiul", 700, 30);

            for(int i=0; i<3; i++){
                books[i].showDetails();
                System.out.println();
            }

            // update addQuantity and sellQuantity
            books[0].addQuantity(5);
            books[0].sellQuantity(3);

            System.out.println("\nAfter update\n" + "Change only One Book\n");
            for(int i=0; i<3; i++){
                books[i].showDetails();
                System.out.println();
            }
        }

}
