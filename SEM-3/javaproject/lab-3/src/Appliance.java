abstract class Appliance {
    abstract void turnon();
}
class Washingmachine extends Appliance{
    void turnon(){
        System.out.println("Press the ON button to turnon the Washing Machine");
    }
}
class Refrigerator extends Appliance{
    void turnon(){
        System.out.println("Switch on the button to turnon the Refrigerator");
    }
    public static void main(String[] args) {
        Washingmachine c1=new Washingmachine();
        c1.turnon();
        Refrigerator f1 = new Refrigerator();
        f1.turnon();
    }
}

