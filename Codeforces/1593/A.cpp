#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int idx = 0;
    if (a[idx]<a[1]) idx=1;
    if (a[idx]<a[2]) idx=2;
    bool isHighest = true;
    for (int i=0;i<3;i++) {
        if (idx!=i && a[i]==a[idx]) {
            isHighest = false;
            break;
        }
    }
    for (int i=0;i<3;i++) {
        if (i==idx) {
            if (isHighest) cout << "0 ";
            else cout << "1 ";
        } else {
            cout << a[idx]-a[i]+1 << " ";
        }
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}