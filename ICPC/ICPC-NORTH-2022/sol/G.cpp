#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int inverse = 5e8+4;
#define ll long long
#define int long long

ll binpow(ll a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main() {
    unordered_map<char,int> mp;
    for (char i='a'; i <= 'z';i++) mp[i] = i-'a'+1;
    int t; cin >> t;
    while (t--) {
        ll ans = 0;
        ll inverse = binpow(2,MOD-2);

        string s; cin >> s;
        int sz = s.size();
        s = ' ' + s;
        for (int i = 1; i <= sz; i++) {
            int l = i, r = sz-i+1;
            int a = ((l%MOD)*(r%MOD))%MOD;
            int b = (l%MOD+r%MOD)%MOD;
            int c = mp[s[i]]%MOD;

            int d = ((a%MOD)*(b%MOD))%MOD;
            int e = (d%MOD * (c%MOD))%MOD;
            int f = (e%MOD*(inverse%MOD))%MOD;
            ans = ((ans%MOD) + (f%MOD))%MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
