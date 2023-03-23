#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back

void solve() {
    ll n, res;
    cin >> n;
    if (n==1) {
        cout << "0\n";
        return;
    }
    res = ceil(sqrtl(n));
    cout << res-1 << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        solve();
    }
}