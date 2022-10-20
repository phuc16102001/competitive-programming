#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long
ll ans;

ll getMod(ll a, ll m) {
    while (a < 0) a += m;
    return a % m;
}

void solve() {
    ans = 0;
    string s;
    cin >> s;
    ll sz = s.size();
    s = ' ' + s;
    for (int i = 1; i <= sz; i++) {
        ll l = i;
        ll r = sz - i + 1;
        ll nSubstr = getMod(l * r, MOD);  //(from left) * (to right)

        // If we have a substr with length x, then we can create another substr with length y=n-x
        // In total, we have (l*r)/2 pairs with length (n+1)
        ll sumLength = getMod(sz + 1, MOD);
        ll value = s[i] - 'a' + 1;

        ll tmp = getMod(getMod(sumLength * nSubstr, MOD) * value, MOD);
        ll cnt = getMod(tmp * 500000004, MOD);
        ans = getMod(ans + cnt, MOD);
    }
    cout << ans << "\n";
}

signed main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}