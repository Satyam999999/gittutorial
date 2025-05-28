 class shape {
    int area();

}
class Rectangle extends shape{
    int area(int l,int b){
        return l*b;
    }
}
class Circle extends shape{
    double area (int radius){
        double result=(3.14*radius*radius);
    return result;
    }
}





// void interest(float percent)
// {
    
// System.out.println("Interst for Fixed Deposits :"+percent);
// }
