abstract  class Employee {
    int salary;
    String name;
    int age;
    abstract void calculatesalary(int money);
    abstract void displaydetails(String name1,int age1);


}
class FullTimeEmployee extends Employee{
    void calculatesalary(int money){
        salary=money;
        System.out.println("FullTimeEmployee Salary is :"+salary);
    }
    void displaydetails(String name1,int age1){
        name=name1;
        age=age1;
        System.out.println("FullTimeEmployee Details :");
        System.out.println("Name:"+name+"\n"+"Age:"+age);
    }
}
class PartTimeEmployee extends Employee{
    void calculatesalary(int money){
        salary=money;
        System.out.println("PartTimeEmployee Salary is :"+salary);
    }
    void displaydetails(String name1,int age1){
        name=name1;
        age=age1;
        System.out.println("PartTimeEmployee Details :");
        System.out.println("Name:"+name+"\n"+"Age:"+age);
    }
    public static void main(String[] args) {
        FullTimeEmployee f1= new FullTimeEmployee();
        f1.calculatesalary(10000);
        f1.displaydetails("KEDAR", 25);
        PartTimeEmployee p1 = new PartTimeEmployee();
        p1.calculatesalary(20000);
        p1.displaydetails("Gautam", 30);
    }
}

