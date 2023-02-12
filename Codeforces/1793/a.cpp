#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#define ll long long
#define inf 1 << 30
ll total;

void solve() {
    ll a, b;
    ll n, m;
    cin >> a >> b >> n >> m;

    ll x = 0;
    ll y = n;
    total = b * n;
    if ((m + 1) * b > a * m) {
        ll k = y / (m + 1);
        x = k * m;
        y = y - k * (m + 1);
        total = a * x + b * y;
        cout << min(total, a*(x+y)) << endl;
    } else {
        cout << total << endl;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}