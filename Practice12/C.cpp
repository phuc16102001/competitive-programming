#include<bits/stdc++.h>
using namespace std;

#define max(a,b) (a>b)?a:b
#define forf(i,a,b) for(int i=a;i<=b;i++)

int n, v;
vector<int> t, a, dp;
int res = 0;

int main() {
    cin >> n >> v;
    t.assign(n+1, 0);
    a.assign(n+1, 0);
    dp.assign(n+1, 0);

    t[0] = 0;
    a[0] = 0;
    dp[0] = 0;
    forf(i,1,n) cin >> t[i];
    forf(i,1,n) cin >> a[i];

    forf(i,1,n) {
        forf(j,0,i-1){
            if (abs(a[i]-a[j])<=v*(t[i]-t[j])) {
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
    }

    cout << res;
}