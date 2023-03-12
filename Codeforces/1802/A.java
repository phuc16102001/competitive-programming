import java.util.*;

public class A {
    private static Scanner sc = new Scanner(System.in);

    public static void solve() {
        int n;
        n = sc.nextInt();

        List<Integer> a = new ArrayList<>();
        for (int i=0;i<n;i++) {
            a.add(sc.nextInt());
        }

        int cntPos = 0;
        int cntNeg = 0;
        for (Integer ai: a){
            if (ai > 0) {
                cntPos++;
            } else {
                cntNeg++;
            }
        }

        int cnt;
        cnt = 0;
        for (int i=0;i<cntPos;i++) {
            cnt++;
            System.out.print(cnt + " ");
        }
        for (int i=0;i<cntNeg;i++) {
            cnt--;
            System.out.print(cnt + " ");
        }
        System.out.println();

        cnt = 0;
        for (int i=0;i<cntNeg;i++) {
            System.out.print("1 0 ");
        }
        for (int i=0;i<cntPos-cntNeg;i++) {
            cnt++;
            System.out.print(cnt + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        int n;
        n = sc.nextInt();
        while ((n--) > 0)
            solve();
    }
}