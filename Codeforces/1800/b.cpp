#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<int> a(256, 0);
    for (int i = 0; i < n; i++) {
        a[s[i]]++;
    }

    int cnt = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        int v = min(a[i], a[toupper(i)]);
        int m = max(a[i] - v, a[toupper(i)] - v);
        cnt += v;
        if (k > 0 && m > 1) {
            v = min(m/2, k);
            cnt += v;
            k -= v;
        }
    }
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}