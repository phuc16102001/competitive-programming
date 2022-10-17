#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
const long long MOD = 1e9+7;

void solve() {
    int n, k;
    long long s = 0, p = 1;
    cin >> n >> k;
    while (k!=0) {
        if (k&1) {
            s = (s+p)%MOD;
        }
        k = k >> 1;
        p = (p*n)%MOD;
    }
    cout << s << endl;
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}