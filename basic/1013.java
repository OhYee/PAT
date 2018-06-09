import java.lang.reflect.Array;
import java.util.*;

class Main {

    public static final int maxn = 110005;
    public static int[] prime = new int[maxn];
    public static boolean[] isPrime = new boolean[maxn];
    public static int pos;

    public static void listPrime(int maxNum) {
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        pos = 0;

        for (int i = 2; i <= maxNum; ++i) {
            if (isPrime[i])
                prime[pos++] = i;
            for (int j = 0; j < pos && i * prime[j] <= maxNum; ++j) {
                isPrime[i * prime[j]] = false;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();

        listPrime(110000);
        int cnt = 0;
        boolean isFirst = true;
        for (int i = n; i <= m; ++i) {
            if (cnt == 10) {
                cnt = 0;
                System.out.print("\n");
                isFirst = true;
            }
            if (isFirst)
                isFirst = false;
            else
                System.out.print(" ");
            cnt++;
            System.out.print(prime[i-1]);
        }
        System.out.print("\n");
        in.close();
    }
}