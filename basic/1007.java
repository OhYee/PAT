import java.lang.reflect.Array;
import java.util.*;

class Main {

    public static final int maxn = 100005;
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
        listPrime(n);
        int cnt = 0;
        for (int i = 1; i < pos && prime[i] <= n; ++i) {
            if (prime[i] - prime[i - 1] == 2)
                cnt++;
        }
        System.out.println(cnt);
        in.close();
    }

}