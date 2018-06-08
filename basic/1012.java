import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String[] read = input.readLine().split(" ");
        int n = Integer.valueOf(read[0]);

        boolean[] has = { false, false, false, false, false };
        int[] A = { 0, 0, 0, 0, -1001 };

        int flag = 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int a = Integer.valueOf(read[i + 1]);
            int b = a % 5;
            if (b == 0 && a % 2 == 0) {
                has[0] = true;
                A[0] += a;
            }
            if (b == 1) {
                has[1] = true;
                A[1] += a * flag;
                flag *= -1;
            }
            if (b == 2) {
                has[2] = true;
                A[2]++;
            }
            if (b == 3) {
                has[3] = true;
                A[3] += a;
                cnt++;
            }
            if (b == 4) {
                has[4] = true;
                A[4] = A[4]> a?A[4]:a;
            }
        }

        for (int i = 0; i < 5; ++i) {
            if (i>0)
                System.out.print(" ");
            if (has[i])
                if (i == 3)
                    System.out.print(Math.round((float) A[3] / cnt * 10) / 10.0);
                else
                    System.out.print(A[i]);
            else
                System.out.print("N");
        }
        System.out.print("\n");
    }
}