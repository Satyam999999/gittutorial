abstract  class Animal {
    abstract void sound();
}
   class Dog extends Animal {
  void sound(){
    System.out.println("Dog sound : Bark");

  }
   }
   class Cat extends Animal{
    void sound(){
        System.out.println("Cat sound : Meow");
    }
    public static void main(String[] args) {
        Dog oscar =new Dog();
        oscar.sound();
        Cat c1 =new Cat();
        c1.sound();
    }
   }

    

