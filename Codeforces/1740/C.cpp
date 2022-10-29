#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<ll> a;

void solve() {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll c1 = 0;
    for (int i=1;i<n;i++){
        c1 = max(c1, a[i]-a[i-1] + a[i]-a[0]);
    }

    ll c2 = 0;
    for (int i=0;i<n-1;i++){
        c2 = max(c2, a[i+1]-a[i] + a[n-1]-a[i]);
    }

    cout << max(c1, c2) << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}