#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back

void solve() {
    int n, k;
    cin >> n >> k;
    int x = floor(-1 + sqrt(1 + 8 * k)) / 2;
    int residual = k - x * (x + 1) / 2;
    vector<int> a;
    for (int i = 0; i < residual; i++) {
        a.pb(31);
    }
    for (int i = residual; i < x; i++) {
        a.pb(1);
    }
    a.pb(-30);
    for (int i = x + 1; i < n; i++) {
        a.pb(-1000);
    }
    for (int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        solve();
    }
}