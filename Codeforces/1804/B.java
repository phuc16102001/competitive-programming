import java.util.*;

public class B {
    private static Scanner sc = new Scanner(System.in);

    public static void solve() {
        int n = sc.nextInt();
        int k = sc.nextInt();
        int d = sc.nextInt();
        int w = sc.nextInt();

        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        int cur = 0;
        int ret = 0;
        while (cur < n) {
            ret += 1;
            int lastMomentPatient = a.get(cur) + w;
            int lastMomentVacine = lastMomentPatient + d;
            int cnt = 0;
            while (cnt < k && cur < n && a.get(cur) <= lastMomentVacine) {
                cnt += 1;
                cur += 1;
            }
        }
        System.out.println(ret);
    }

    public static void main(String args[]) {
        int n = sc.nextInt();
        while (n-- > 0)
            solve();
    }
}