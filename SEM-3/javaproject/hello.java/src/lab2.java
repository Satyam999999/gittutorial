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
