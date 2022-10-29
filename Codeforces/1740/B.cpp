#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x > y) {
            res += 2 * y;
            a[i] = x;
        } else {
            res += 2 * x;
            a[i] = y;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        res += a[i] - a[i - 1];
    }
    res += a[0] + a[n - 1];
    cout << res << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}