import java.util.*;

class Main {
    public static final int maxn = 105;
    public static int[] a = new int[maxn];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt() % n;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(a[(i + n - m) % n]);
        }
        System.out.print("\n");

        in.close();
    }
}