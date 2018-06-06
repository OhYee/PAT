import java.util.ArrayList;
import java.util.Scanner;

class Main {
    static Scanner in;

    static String[] pinyin = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

    public static void getPinYin(int n) {
        ArrayList<String> output = new ArrayList<String>();
        while (n > 0) {
            output.add(0, pinyin[n % 10]);
            n /= 10;
        }

        boolean first = true;
        for (String i : output) {
            if (first == true)
                first = false;
            else
                System.out.print(" ");
            System.out.print(i);
        }
        System.out.print("\n");
    }

    public static void main(String args[]) {
        in = new Scanner(System.in);
        String s = in.next();
        int sum = 0;
        for (int i = 0; i < s.length(); ++i)
            sum += s.charAt(i) - '0';
        getPinYin(sum);
        in.close();
    }
}