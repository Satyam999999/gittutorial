package lab3;

class vehicle{
    String name; 
    int number;
    void move(String vehiclename, int vehiclenumber){
        name=vehiclename;
        number=vehiclenumber;
        System.out.println("Vehicle name:"+name+"\n"+"Vehicle number:"+number);
    }
}
class Bike extends vehicle{
    void move(String vehiclename, int vehiclenumber){
        name=vehiclename;
        number=vehiclenumber;
        System.out.println("Bike name:"+name+"\n"+"Bike number:"+number);
    }
}
class Car extends vehicle{
    void move(String vehiclename, int vehiclenumber){
        name=vehiclename;
        number=vehiclenumber;
        System.out.println("Car name:"+name+"\n"+"Car number:"+number);
    }
    public static void main(String[] args) {
        Bike b1 = new Bike();
        b1.move("pulsar",123456);
        Car c1= new Car();
        c1.move("Mercedes",678901);

    }
}