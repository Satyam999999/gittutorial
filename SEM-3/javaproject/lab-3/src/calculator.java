

public class calculator {
	int add(int a,int b,int c, int d) {
		return (a+b+c+d);
	}
	
	int add(int a, int b, int c) {
		return (a+b+c);
	}
	
	int add(int a, int b) {
		return (a+b);
	}
	public static void main(String[] args) {
		calculator c1=new calculator();
		System.out.println(c1.add(1,2 ));
		System.out.println(c1.add(1 ,2 ,3));
		System.out.println(c1.add(1,2,3,4));
	}
}