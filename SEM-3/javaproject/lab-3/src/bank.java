public class bank {
   
    void interest(int percent)
    {
   
System.out.println("Interest for Savings :"+percent);
    }
  
    void interest(double percent)
    {
       
System.out.println("Interest for Recurring Deposits :"+percent);
    }
    public static void main(String[] args) {
       bank b1=new bank();
       b1.interest(10);
       b1.interest(12.1);
       b1.interest(7.25);

    }
}
