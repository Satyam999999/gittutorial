import java.util.Scanner;
public class Calculator {
     int add(int a, int b) {
        int ans = a + b;
        return ans;
    }

     int differnce(int a, int b) {
        int ans = a - b;
        return ans;
    }

    int multiply(int a, int b) {
        int ans = a * b;
        return ans;
    }

    float division(int a, int b) {
        float ans = a / b;
        return ans;
    }

    public static void main(String[] args){
    Calculator result =new Calculator();
    Scanner scan=new Scanner(System.in);
    System.out.println("ENTER 2 INTEGERS ");
    int c=scan.nextInt();
    int d=scan.nextInt();
     System.out.println(result.add(c,d));
    System.out.println(result.differnce(c,d));
    System.out.println(result.multiply(c,d));
    System.out.println(result.division(c,d));
 }

}
