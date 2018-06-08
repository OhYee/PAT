import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        boolean isFirst = true;
        while (in.hasNextInt()) {
            int a = in.nextInt();
            int n = in.nextInt();

            if (n != 0) {
                if (isFirst) {
                    isFirst = false;
                } else {
                    System.out.print(" ");
                }
                System.out.printf("%d %d", a * n, n - 1);
            }
        }
        if (isFirst){
            System.out.print("0 0");
        }
        System.out.print("\n");

        in.close();
    }
}