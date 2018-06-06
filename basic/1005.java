import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


class Main {
    public static Scanner in;
    public static ArrayList<Integer> lst;
    public static ArrayList<Boolean> isKeyNum;

    public static void Callatz(int n) {
        boolean isFirst = true;
        while (n > 1) {
            if (isFirst) {
                isFirst = false;
            } else {
                int idx = lst.indexOf(n);
                if (idx != -1) {
                    isKeyNum.set(idx, false);
                }
            }
            if (n % 2 == 1)
                n = (3 * n + 1) / 2;
            else
                n /= 2;
        }
    }

    public static void main(String args[]) {
        in = new Scanner(System.in);
        int n = in.nextInt();
        lst = new ArrayList<Integer>();
        isKeyNum = new ArrayList<Boolean>();

        for (int i = 0; i < n; ++i) {
            int a = in.nextInt();
            lst.add(Integer.valueOf(a));
            isKeyNum.add(true);
        }
        Collections.sort(lst);
        for (int i : lst) {
            Callatz(i);
        }
        boolean isFirst = true;
        for (int i = n - 1; i >= 0; --i) {
            if (isKeyNum.get(i)) {
                if (isFirst)
                    isFirst = false;
                else
                    System.out.print(' ');
                System.out.print(lst.get(i));
            }
        }
        System.out.print('\n');
        in.close();
    }
}