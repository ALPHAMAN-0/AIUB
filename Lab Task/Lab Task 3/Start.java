/*
 *               SIAM HOSSAIN
 *              ID: 24-56637-1
 */
class StoryBook {
        private String isbn;
        private String bookTitle;
        private String authorName;
        private double price;
        private int availableQuantity;
        private String category;
        private static double discountRate;
        
        StoryBook(){
            //default constructor
        }

        StoryBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, String category){
            this.isbn = isbn;
            this.bookTitle = bookTitle;
            this.authorName = authorName;
            this.price = price;
            this.availableQuantity = availableQuantity;
            this.category = category;
        }

        public static void setDiscountRate(double discountRate){
            StoryBook.discountRate = discountRate;
        }

        public static double getDiscountRate(){
            return StoryBook.discountRate;
        }
        //setter
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

        //getter
        public String getIsbn(){
            return this.isbn;
        }
        public String getBookTitle(){
            return this.bookTitle;
        }
        public String getAuthorName(){
            return this.authorName;
        }
        public double getPrice(){
            return this.price;
        }
        public int getAvailableQuantity(){
            return this.availableQuantity;
        }
        public String getCategory(){
            return this.category;
        }

        public void addQuantity(int amount){
            this.availableQuantity += amount;
        }

        public void sellQuantity(int amount){
            if(this.availableQuantity >= amount){
                this.availableQuantity -= amount;
            }
            else{
                System.out.println("Not enough books in stock");
            }
        }

        public void showDetails(){
            System.out.println("ISBN: "+this.isbn);
            System.out.println("Book Title: "+this.bookTitle);
            System.out.println("Author Name: "+this.authorName);
            System.out.println("Price: "+this.price);
            System.out.println("Available Quantity: "+this.availableQuantity);
            System.out.println("Category: "+this.category);
        }
}

class TextBook{
    private String isbn;
    private String bookTitle;
    private String authorName;
    private double price;
    private int availableQuantity;
    private int standard;
    private static double discountRate;

    TextBook(){
        //default constructor
    }
    TextBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, int standard){
        this.isbn = isbn;
        this.bookTitle = bookTitle;
        this.authorName = authorName;
        this.price = price;
        this.availableQuantity = availableQuantity;
        this.standard = standard;
    }

    public static void setDiscountRate(double discountRate){
        TextBook.discountRate = discountRate;
    }

    public static double getDiscountRate(){
        return TextBook.discountRate;
    }

    //setter
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
    public void setStandard(int standard){
        this.standard = standard;
    }

    //getter
    public String getIsbn(){
        return this.isbn;
    }
    public String getBookTitle(){
        return this.bookTitle;
    }
    public String getAuthorName(){
        return this.authorName;
    }
    public double getPrice(){
        return this.price;
    }
    public int getAvailableQuantity(){
        return this.availableQuantity;
    }
    public int getStandard(){
        return this.standard;
    }

    public void addQuantity(int amount){
        this.availableQuantity += amount;
    }

    public void sellQuantity(int amount){
        if(this.availableQuantity >= amount){
            this.availableQuantity -= amount;
        }
        else{
            System.out.println("Not enough books in stock");
        }
    }

    public void showDetails(){
        System.out.println("ISBN: "+this.isbn);
        System.out.println("Book Title: "+this.bookTitle);
        System.out.println("Author Name: "+this.authorName);
        System.out.println("Price: "+this.price);
        System.out.println("Available Quantity: "+this.availableQuantity);
        System.out.println("Standard: "+this.standard);
    }

}
public class Start{
    public static void main(String[] args){
        StoryBook storyBook1 = new StoryBook("1234", "The Alchemist", "Paulo Coelho", 500, 100, "Adventure");
        storyBook1.showDetails();
        storyBook1.addQuantity(50);
        storyBook1.sellQuantity(10);
        storyBook1.showDetails();

        TextBook textBook1 = new TextBook("5678", "Math", "John Doe", 200, 50, 5);
        textBook1.showDetails();
        textBook1.addQuantity(20);
        textBook1.sellQuantity(10);
        textBook1.showDetails();
    }
}
