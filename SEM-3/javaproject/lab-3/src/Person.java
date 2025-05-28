public class Person{
String name;
int age;
void details(String name1,int age1){
    name=name1;
    age=age1;
    System.out.println("Person Details:");
    System.out.println("Person Name:"+name+"\n"+"Person age:"+age);


}
}
class Student extends Person{
void studentdetails(String name1,int age1){
    name=name1;
    age=age1;
    System.out.println("Following are Student Details");
    System.out.println("Student Name:"+name+"\n"+"Student age:"+age);
  }
}
class Teacher extends Person{
    void teacherdetails(String name1,int age1){
        name=name1;
        age=age1;
        System.out.println("Following are Teacher Details");
        System.out.println("Teacher Name:"+name+"\n"+"Teacher age:"+age);
      }

    public static void main(String[] args)  {
        Student s1= new Student();
        s1.studentdetails("Satyam",20);
        s1.details("Satyam", 20);
 Teacher t1=new Teacher();
 t1.teacherdetails("Gautam",55);
 t1.details("Gautam",55);
    }
}
