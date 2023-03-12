import java.util.*;

public class C {
    private static Scanner sc = new Scanner(System.in);
    public static List<Long> sumForce = new ArrayList<>();

    public static class Pair {
        public int first;
        public int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair p = (Pair) o;
                return p.first == first && p.second == second;
            }
            return false;
        }

    }

    public static void solve() {
        int n = sc.nextInt();
        int x = sc.nextInt();
        int p = sc.nextInt();
        Set<Pair> set = new HashSet<>();

        int cnt = x;
        for (int i = 1; i <= p; i++) {
            cnt = (cnt + i % n) % n;

            if (cnt == 0) {
                System.out.println("YES");
                return;
            }
            Pair pair = new Pair(i % n, cnt);
            if (set.contains(pair)) {
                System.out.println("NO");
                return;
            }
            set.add(pair);
        }
        System.out.println("NO");

    }

    public static void main(String args[]) {
        int n = sc.nextInt();
        while (n-- > 0)
            solve();
    }
}