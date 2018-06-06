import java.util.Scanner;

class Main {
    public static Scanner in;

    public static int getAns(int n) {
        int cnt = 0;
        while (n > 1) {
            if (n % 2 == 1)
                n = (3 * n + 1) / 2;
            else
                n /= 2;
            cnt += 1;
        }
        return cnt;
    }

    public static void main(String args[]) {
        in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(getAns(n));
        in.close();
    }
}