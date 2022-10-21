#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll res;
int n, q, x, type, cntOdd, cntEven;
vector<int> a;

void solve() {
    res = 0;
    cntOdd = 0;
    cntEven = 0;

    cin >> n >> q;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
        if (a[i] % 2) {
            cntOdd++;
        } else {
            cntEven++;
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> type >> x;
        if (type == 0) {
            res += x * cntEven;
            if (x % 2) {
                cntOdd += cntEven;
                cntEven = 0;
            }
        } else {
            res += x * cntOdd;
            if (x % 2) {
                cntEven += cntOdd;
                cntOdd = 0;
            }
        }
        cout << res << endl;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}