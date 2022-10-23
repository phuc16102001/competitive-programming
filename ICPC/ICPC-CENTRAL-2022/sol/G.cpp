#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int, int>
#define INF 1e18

int n, k;
vector<ll> a;
vector<ll> prefix;
vector<vector<ll>> dp;

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    prefix.assign(n, 0);
    dp.assign(2, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    prefix[0] = a[0];
    for (ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    ll res = -INF;
    for (ll i = 0; i <= n - k; i++) {
        ll sumPre = prefix[i + k - 1] - prefix[i] + a[i];
        dp[0][i] = sumPre;
        dp[1][i] = -sumPre;
        if (i >= k) {
            dp[0][i] = max({dp[0][i], dp[1][i - k] + sumPre});
            dp[1][i] = max({dp[1][i], dp[0][i - k] - sumPre});
        }
        if (i>0) {
            dp[0][i] = max(dp[0][i], dp[0][i-1]); 
            dp[1][i] = max(dp[1][i], dp[1][i-1]); 
        }
        res = max({res, dp[0][i], dp[1][i]});
    }
    // cout << "Debug\n";
    // for (int x = 0; x < 2; x++) {
    //     for (int i = 0; i <= n - k; i++) {
    //         cout << dp[x][i] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}