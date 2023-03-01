#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define MOD 998244353
#define ll long long

void solve() {
    ll l, r;
    cin >> l >> r;

    ll nMax = floor(log2(r * 1.0 / l)) + 1;

    ll upper = r / (1 << (nMax - 1));
    ll lower = r / (3 * (1 << (nMax - 2)));

    ll res;
    if (lower >= l) {
        res = ((((lower % MOD - l % MOD + 1 + MOD) % MOD) * (nMax % MOD)) % MOD + (upper % MOD - lower % MOD + MOD) % MOD) % MOD;
    } else {
        res = (upper % MOD - l % MOD + MOD + 1) % MOD;
    }
    cout << nMax << " ";
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}