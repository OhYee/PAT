import java.util.ArrayList;
import java.util.Scanner;
import java.util.Collections;

class Node implements Comparable<Node> {
    private String name;
    private String id;
    private int score;

    public Node(String _name, String _id, int _score) {
        this.name = _name;
        this.id = _id;
        this.score = _score;
    }

    public void print() {
        System.out.printf("%s %s\n", name, id, score);
    }

    @Override
    public int compareTo(Node rhs) {
        return this.score - rhs.score;
    }
}

class Main {
    static Scanner in;

    public static void main(String[] args) {
        in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Node> students = new ArrayList<Node>();
        for (int i = 0; i < n; ++i) {
            String name = in.next();
            String id = in.next();
            int score = in.nextInt();
            students.add(new Node(name, id, score));
        }
        Collections.sort(students);

        
        students.get(n-1).print();
        students.get(0).print();

        in.close();
    }
}
