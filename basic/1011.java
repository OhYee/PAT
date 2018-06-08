import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; ++i) {
            long a = in.nextLong();
            long b = in.nextLong();
            long c = in.nextLong();

            System.out.printf("Case #%d: %s\n", i, a + b > c ? "true" : "false");
        }
        in.close();
    }
}