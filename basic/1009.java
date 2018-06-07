import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();

        List<String> list = Arrays.asList(s.split(" "));
        Collections.reverse(list);

        boolean isFirst = true;
        for (String c : list) {
            if (isFirst) {
                isFirst = false;
            } else {
                System.out.print(" ");
            }
            System.out.print(c);
        }
        System.out.print("\n");
        in.close();
    }
}