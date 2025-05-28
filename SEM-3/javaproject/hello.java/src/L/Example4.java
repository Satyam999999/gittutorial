package L;

// // // public class Fun {
// // //     int add(int a,int b){
// // //         return a+b;

// // //     }
// // //     public static void main(String[] args) {
// // //         Fun ex= new Fun();
// // //         System.out.println(ex.add(10, 20));
// // //     }
// // // }
// // public class Fun {
// //         void Force() {
// //             System.out.println("There are four fundamental forces.");
// //         }
// //     }
    
// //     class Gravitational extends Fun {
// //         void Gravity() {
// //             System.out.println("Fruits fall to the ground due to gravitational Force.");
// //         }
    
    
  
// //         public static void main(String[] args) {
// //             Gravitational G = new Gravitational();
// //             G.Force();
// //             G.Gravity();
// //         }
// //     }
// class FundamentalForce {
//   void Force() {
//        System.out.println("There are four fundamental forces.");
//     }
//  }

// class Gravitational extends FundamentalForce {
//     void Gravity() {
//         System.out.println("Fruits fall to the ground due to gravitational Force.");
//     }
// }

// class Electromagnetic extends FundamentalForce {
//     void Particles() {
//         System.out.println("The electromagnetic force acts between charged particles");
//     }

//     public static void main(String[] args) {
//         System.out.println("Child 1:");
//         Gravitational G = new Gravitational();
//         G.Force();
//         G.Gravity();
        
//         System.out.println();
//         System.out.println("Child 2");
//         Electromagnetic em = new Electromagnetic();
//         em.Force();
//         em.Particles();
//     }
// }


// class NuclearForce extends FundamentalForce {
//     void Nuclear() {
//         System.out.println("Nuclear Forces are of two types;");
//         System.out.println("Strong Nuclear Force");
//         System.out.println("Weak Nuclear Force");
//     }
// }

// class StrongNuclearForce extends NuclearForce {
//     void Strong() {
//         System.out.println("Strong Nuclear Force is responsible for the underlying stability of matter.");
//     }
// }

// class MultilevelInheritance {
//     public static void main(String[] args) {
//         StrongNuclearForce st = new StrongNuclearForce();
//         st.Force();
//         st.Nuclear();
//         st.Strong();
//     }
// }



// class AddMethods {
//     static int AddNums(int a, int b) {
//         return (a+b);
//     }
    
//     static int AddNums(int a, int b, int c) {
//         return (a+b+c);
//     }
    
//     static double AddNums(double a, double b) {
//         return (a+b);
//     }



//     public static void main(String[] args) {
//         System.out.println("Addition of two integers: "+ AddMethods.AddNums(6, 11));
//         System.out.println("Addition of three integers: "+ AddMethods.AddNums(6, 11, 5));
//         System.out.println("Addition of two decimal numbers: "+ AddMethods.AddNums(6.3, 2.8));
//     }
// } 


// class Color {
//     void paint() {
//         System.out.println("I'm Painting.");
//     }
// }
    
// class RedPaint extends Color {
//     void paint() {
//         System.out.println("I'm Painting with Red color.");
//     }
// }
    
// class BluePaint extends Color {
//     void paint() {
//         System.out.println("I'm Painting with Blue color.");
//     }





//     public static void main(String[] args) {
//         Color c;
//         c = new RedPaint();
//         c.paint();
//         c = new BluePaint();
//         c.paint();
//     }
// }



// abstract class Fruits {
//     public abstract void taste();
//     public void eat() {
//         System.out.println("Let's eat Fruits.");
//     }
// }

// class Mango extends Fruits {
//     public void taste() {
//         System.out.println("Mango is sweet.");
//     }

//     public static void main(String[] args) {
//         Mango m = new Mango();
//         m.eat();
//         m.taste();
//     }
// }


// interface Fruits {
//     public abstract void taste();
//     public void eat();
// }

// class Mango implements Fruits {
    
//     public void taste() {
//         System.out.println("Mango is sweet.");
//     }
    
//     public void eat() {
//         System.out.println("Let's eat Fruits.");
//     }

//     public static void main(String[] args) {
//         Mango m = new Mango();
//         m.eat();
//         m.taste();
//     }
// }