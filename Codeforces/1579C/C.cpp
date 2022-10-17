#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);

const int MAXN = 11;
const int MAXM = 20;

struct DPType {
    int l=-1, r=-1, d=-1;
};

void solve() {
    
    int n, m, k;
    char a[MAXN][MAXM] = {'.'};
    DPType dp[MAXN+1][MAXM+1];
    
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
            if (a[i][j]=='*') {
                dp[i][j].l=dp[i-1][j-1].l+1;
                dp[i][j].r=dp[i-1][j+1].r+1;
                dp[i][j].d=min(dp[i][j].l,dp[i][j].r);
            }
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << dp[i][j].d << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "====\n";
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (dp[i][j].d>=k) {
                // cout << i << " " << j << endl;
                for (int x=0;x<=dp[i][j].d;x++) {
                    a[i-x][j-x]='.';
                    a[i-x][j+x]='.';
                }
            }
        }
    }
    bool ok = true;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j]!='.') {
                ok=false;
                break;
            }
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (ok?"YES\n":"NO\n");
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}