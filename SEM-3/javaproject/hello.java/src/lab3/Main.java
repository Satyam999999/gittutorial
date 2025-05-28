//package q1;

abstract class Vehicle {
 String vehicleNumber;
    String model;
    int yearOfManufacture;

    public Vehicle(String vehicleNumber, String model, int yearOfManufacture) {
        this.vehicleNumber = vehicleNumber;
        this.model = model;
        this.yearOfManufacture = yearOfManufacture;
    }

    public abstract double calculateMileage();

    public void displayDetails() {
        System.out.println("Vehicle Number: " + vehicleNumber);
        System.out.println("Model: " + model);
        System.out.println("Year of Manufacture: " + yearOfManufacture);
        System.out.println("Mileage: " + calculateMileage() + " km/l");
    }
}



package q1;

class Car extends Vehicle {
    public Car(String vehicleNumber, String model, int yearOfManufacture) {
        super(vehicleNumber, model, yearOfManufacture);
    }

   // @Override
    public double calculateMileage() {
        return 15; // Car mileage is 15 km/l
    }
}




package q1;


class Truck extends Vehicle {
    public Truck(String vehicleNumber, String model, int yearOfManufacture) {
        super(vehicleNumber, model, yearOfManufacture);
    }

    @Override
    public double calculateMileage() {
        return 8; // Truck mileage is 8 km/l
    }
}


package q1;

class Motorcycle extends Vehicle {
    public Motorcycle(String vehicleNumber, String model, int yearOfManufacture) {
        super(vehicleNumber, model, yearOfManufacture);
    }

    @Override
    public double calculateMileage() {
        return 40; // Motorcycle mileage is 40 km/l
    }
}

package q1;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<Vehicle> vehicleList = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.println("1. Add a new vehicle");
            System.out.println("2. Display all vehicles");
            System.out.println("3. Display total number of vehicles");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addNewVehicle(sc);
                    break;
                case 2:
                    displayAllVehicles();
                    break;
                case 3:
                    System.out.println("Total number of vehicles: " + vehicleList.size());
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

  public static void addNewVehicle(Scanner sc) {
        System.out.println("Choose vehicle type:");
        System.out.println("1. Car");
        System.out.println("2. Truck");
        System.out.println("3. Motorcycle");
        System.out.print("Enter your choice: ");
        int vehicleType = sc.nextInt();
       sc.nextLine();  // Consume newline

        System.out.print("Enter vehicle number: ");
        String vehicleNumber = sc.nextLine();
        System.out.print("Enter model: ");
        String model = sc.nextLine();
        System.out.print("Enter year of manufacture: ");
        int year = sc.nextInt();

        Vehicle vehicle;
        switch (vehicleType) {
            case 1:
                vehicle = new Car(vehicleNumber, model, year);
                break;
            case 2:
                vehicle = new Truck(vehicleNumber, model, year);
                break;
            case 3:
                vehicle = new Motorcycle(vehicleNumber, model, year);
                break;
            default:
                System.out.println("Invalid vehicle type.");
                return;
        }

        vehicleList.add(vehicle);
        System.out.println("Vehicle added successfully!");
    }  

    public static void displayAllVehicles() {
        if (vehicleList.isEmpty()) {
            System.out.println("No vehicles added.");
        } else {
            for (Vehicle vehicle : vehicleList) {
                vehicle.displayDetails();
                System.out.println("------------------------");
            }
        }
    }
}

