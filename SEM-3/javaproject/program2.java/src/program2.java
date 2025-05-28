
// public class hello {
//     public static void main(String[] args){
//         System.out.println("HElLO");
//     }
// }
//package inheritance;

 class program2 {
	String memberName;
	String bookAdded;
	String bookIssue;
	
	void bookissue(String book) {
		bookIssue=book;
	}
	void bookadded(String bookname) {
		bookAdded=bookname;
	}
	program2 (String  name)
	{
		memberName=name;
	}

	public static void main(String[] args)  {
		// TODO Auto-generated constructor stub
		program2 user = new program2("Satyam");
		user.bookissue("Physics");
		user.bookadded("Maths");
		System.out.println("Member name:"+user.memberName+"Bookissued :"+user.bookIssue+"Bookadded:"+ user.bookAdded);
	}

}