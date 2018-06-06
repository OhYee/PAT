import java.util.Scanner;

class Main {
    static Scanner in;

    public static boolean check(String s) {
        boolean hasP = false;
        boolean hasT = false;
        boolean wrong = false;
        int[] aNums = { 0, 0, 0 };

        for (int i = 0; i < s.length() && !wrong; ++i) {
            char c = s.charAt(i);
            if (c == 'P') {
                if (hasP == true) {
                    wrong = true;
                } else {
                    hasP = true;
                }
                continue;
            }
            if (c == 'T') {
                if (hasT == true) {
                    wrong = true;
                } else {
                    hasT = true;
                }
                continue;
            }
            if (c == 'A') {
                if (!hasP && !hasT) {
                    ++aNums[0];
                }
                if (hasP && !hasT) {
                    ++aNums[1];
                }
                if (hasP && hasT) {
                    ++aNums[2];
                }
                if (!hasP && hasT) {
                    wrong = true;
                }
                continue;
            }
            wrong = true;
        }
        // System.out.printf("%s %b %d %d %d\n",s,wrong,aNums[0],aNums[1],aNums[2]);
        return hasP && hasT && (!wrong && (aNums[0] * aNums[1] == aNums[2]) && aNums[1] > 0) == true;
    }

    public static void main(String args[]) {
        in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            String s = in.next();
            if (check(s) == true)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
        in.close();
    }
}