#include <iostream>
using namespace std;

void solve() {
    int n, a[200000], dp[200000];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        dp[i] = a[i];
    }

    for (int i = 0; i < n;i++) {
        if (i+a[i]<n) {
            dp[i + a[i]] = max(dp[i + a[i]], dp[i] + a[i + a[i]]);
        }
    }

    int result = dp[0];
    // cout << dp[0] << " ";
    for (int i = 1;i<n;i++) {
        result = max(result, dp[i]);
        // cout << dp[i] << " ";
    }
    // cout << endl;

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}