import java.util.*;

public class A {
    private static Scanner sc = new Scanner(System.in);

    public static void solve() {
        int a = Math.abs(sc.nextInt());
        int b = Math.abs(sc.nextInt());
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        int diff = b - a;
        int small = a;
        int ret = small * 2 + 2 * diff;
        if (diff>0){
            ret -= 1;
        }
        System.out.println(ret);
    }

    public static void main(String args[]) {
        int n = sc.nextInt();
        while (n-- > 0)
            solve();
    }
}