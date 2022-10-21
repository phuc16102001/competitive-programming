#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int getLastBit(int n) {
    int cnt = 0;
    while ((n & 1) == 0) {
        n >>= 1;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n;
    int lastBit = 0;
    cin >> n;
    vector<int> a(n, 0), lastBitOfI;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    lastBit = getLastBit(a[0]);
    for (int i = 1; i < n; i++) {
        lastBit += getLastBit(a[i]);
        lastBitOfI.pb(getLastBit(i + 1));
    }

    sort(lastBitOfI.begin(), lastBitOfI.end(), [](int a, int b) {
        return a>b;
    });
    int cnt = 0;
    for (int i = 0; i < lastBitOfI.size(); i++) {
        if (lastBit >= n) {
            break;
        }
        cnt++;
        lastBit += lastBitOfI[i];
    }
    if (lastBit >= n) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}