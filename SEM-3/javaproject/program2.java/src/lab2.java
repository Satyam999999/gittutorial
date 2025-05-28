

//Program3/ class program1 {

// // int balance;
// // void deposit(int amount){
// // 	balance=balance+amount;
// // }
// // void withdraw(int amount){
	
// // balance=balance-amount;
// // 	}


// // 	public static void main(String[] args) {
// // 		// TODO Auto-generated method stub
// // 		program1 ans = new program1();
// // 		ans.balance=1000;
// // 		System.out.println("Balance is :"+ ans.balance);
// // 		ans.withdraw(500);
// // 		System.out.println("Updated Balance is :"+ ans.balance);
// // 		ans.deposit(1000);
// // 		System.out.println("Updated Balance is :"+ ans.balance);
// // }
// // }






//  class program2 {
// 	String memberName;
// 	String bookAdded;
// 	String bookIssue;
	
// 	void bookissue(String book) {
// 		bookIssue=book;
// 	}
// 	void bookadded(String bookname) {
// 		bookAdded=bookname;
// 	}
// 	program2 (String  name)
// 	{
// 		memberName=name;
// 	}

//	public static void main(String args[]) {
// 		// TODO Auto-generated constructor stub
// 		program2 user = new program2("Satyam");
// 		user.bookissue("Physics");
// 		user.bookadded("Maths");
// 		System.out.println("Member name:"+user.memberName +"\n");
// 		System.out.println("Bookissued :"+user.bookIssue+"\n");
// 		System.out.println("Bookadded:"+ user.bookAdded+"\n");
// 	}

// }



//package inheritance;


public class lab2 {
    String item;
    int totalprice;

    void itemname(String object, int price) {
        item = object;
        totalprice = price;
    }
}
class Discount extends lab2{
    void discountprice(int discount) {
        totalprice = totalprice - (int)(totalprice * ((double) discount / 100));
    }



public static void main(String args[]) {
        Discount user = new Discount();
        user.itemname("TV", 10000);
        user.discountprice(10);
        System.out.println("Item name is: " + user.item + " Total Price is: " + user.totalprice);
    }
}

