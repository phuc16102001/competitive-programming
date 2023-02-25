#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

vector<int> a, sumOccur, lastOccur;

void solve() {
    int n, m;
    cin >> n >> m;

    a.assign(n, 0);
    sumOccur.assign(n+m+1, 0);
    lastOccur.assign(n+m+1, -1);

    ll res = 0;
    ll s = n;
    ll prevS = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lastOccur[a[i]]=0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int take_out = a[u - 1];
        ll f_remove = 0, f_add = 0;

        if (take_out != v) {
            if (lastOccur[take_out]==-1) {
                lastOccur[take_out] = i+1;
            } else {
                sumOccur[take_out] += (i+1-lastOccur[take_out]);
                lastOccur[take_out] = -1;
            }
            if (lastOccur[v]==-1) {
                lastOccur[v] = i+1;
            } else {
                sumOccur[v] += (i+1-lastOccur[v]);
                lastOccur[v] = -1;
            }
            f_remove = sumOccur[take_out]+(lastOccur[take_out]!=-1)*(i+1-lastOccur[take_out]);
            f_add = sumOccur[v]+(lastOccur[v]!=-1)*(i+1-lastOccur[v]);
        }

        ll p1 = (n * 2);
        ll p2 = i+1;
        res +=  p1*p2;
        res -= (prevS - f_remove + f_add);
        prevS = prevS + n - f_remove + f_add;
        a[u - 1] = v;
    }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}