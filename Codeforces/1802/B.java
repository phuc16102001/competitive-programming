import java.util.*;

public class B {
    private static Scanner sc = new Scanner(System.in);

    public static void solve() {
        int n = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        List<Integer> dp = new ArrayList<>();

        int cntBuy = 0;
        int cntUse = 0;
        int cntPig = 0;
        dp.add(0);
        dp.add(1);
        dp.add(2);
        for (int i=0;i<n;i++) {
            a.add(sc.nextInt());
            if (a.get(i)==1) {
                if (cntUse==cntBuy) {
                    cntBuy+=1;
                }
                cntUse += 1;
                cntPig += 1;
                
                if (cntPig>=dp.size()) {
                    dp.add(dp.get(cntPig-2)+1);
                }
            } else {
                cntUse = dp.get(cntPig);
            }
        }
        System.out.println(cntBuy);
    }

    public static void main(String args[]) {
        int n = sc.nextInt();
        while (n-- > 0) {
            solve();
        }
    }
}