import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String ans = "";
        int pos = s.length();
        for (int i = 0; i < s.length(); ++i) {
            int cnt = s.charAt(i) - '0';
            for (int j = 1; j <= cnt; ++j) {
                if (pos == 3)
                    ans += "B";
                if (pos == 2)
                    ans += "S";
                if (pos == 1)
                    ans += j;
            }
            --pos;
        }
        System.out.println(ans);
        in.close();
    }
}