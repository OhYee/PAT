import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main {
    public static final String[] weekday = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

    public static void main(String[] args) throws Exception{

        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        String a = input.readLine();
        String b = input.readLine();
        String c = input.readLine();
        String d = input.readLine();

        int A = -1, B = -1, C = -1;

        int len = Math.min(a.length(), b.length());
        for (int i = 0; i < len; ++i) {
            char ac = a.charAt(i);
            char bc = b.charAt(i);
            if (A == -1) {
                if (ac == bc && ac >= 'A' && ac <= 'G') {
                    A = i;
                }
            } else {
                if (ac == bc && ((ac >= 'A' && ac <= 'N') || (ac >= '0' && ac <= '9'))) {
                    B = i;
                    break;
                }
            }
        }

        len = Math.min(c.length(), d.length());
        for (int i = 0; i < len; ++i) {
            char ac = c.charAt(i);
            char bc = d.charAt(i);
            if (ac == bc && ((ac >= 'A' && ac <= 'Z') || (ac >= 'a' && ac <= 'z'))) {
                C = i;
                break;
            }
        }

        System.out.printf("%s %02d:%02d\n", weekday[a.charAt(A) - 'A'],
                (a.charAt(B) <= '9' ? a.charAt(B) - '0' : a.charAt(B) - 'A' + 10), C);

    }
}