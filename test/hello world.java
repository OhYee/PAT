import java.util.Scanner;

class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String name = in.next();
        System.out.println("Hello " + name);
        in.close();
    }
}