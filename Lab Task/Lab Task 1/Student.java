/*
 *          SIAM HOSSAIN
 *          ID 24-56637-1
 */
public class Student {
    private String name;
    private int id;
    private double cgpa;

    public Student(String name, int id, double cgpa) {
        this.name = name;
        this.id = id;
        this.cgpa = cgpa;
    }
    Student(){
        //default constructor
    }

    // setter and getter
    public void setName(String name) {
        this.name = name;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }


    public String getName() {
        return name;
    }
    public int getId() {
        return id;
    }
    public double getCgpa() {
        return cgpa;
    }


    public void showInfo(){
        System.out.println("Name: "+name);
        System.out.println("ID: "+id);
        System.out.println("CGPA: "+cgpa);
    }

    public static void main(String[] args) {
        // creating object using parameterized constructor
        Student student = new Student("Siam", 566371, 3.75);
        student.showInfo();

        // creating object using default constructor
        Student student1 = new Student();
        student1.setName("Siam");
        student1.setId(566371);
        student1.setCgpa(3.75);
        student1.showInfo();
        
    }
}
