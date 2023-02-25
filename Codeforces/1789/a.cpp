#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (gcd(a[i], a[j]) <= 2) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}