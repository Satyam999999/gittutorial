

class BankAccount{
	int balance;
	void withdraw(int amount) {
		balance=balance-amount;
	}
	void deposit(int amount) {
		balance=balance+amount;
	}
}

public class program1 {
	
	public static void main(String args[]) {
		BankAccount kamal=new BankAccount();
		kamal.balance=10000;
		System.out.println("Your remaining balance is " + kamal.balance);
		kamal.withdraw(5000);
		System.out.println("Your remaining balance is " + kamal.balance);
		kamal.deposit(10000);
		System.out.println("Your remaining balance is " + kamal.balance);
	}
	
}