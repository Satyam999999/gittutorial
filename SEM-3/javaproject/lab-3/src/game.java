public class game {
    void start(){
        System.out.println("Game Starts");
    }
}
class Cricket extends game{
    void start(){
        System.out.println("Swing the bat to start the game");
    }
}
class Football extends game{
    void start(){
        System.out.println("Kick the football to start the game");
    }
    public static void main(String[] args) {
        Cricket c1=new Cricket();
        c1.start();
        Football f1 = new Football();
        f1.start();
    }
}
