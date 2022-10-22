#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

int n;
vector<int> a;

ll getMod(ll a, ll m) {
    while (a < 0) a += m;
    return a % m;
}

ll gcdExtended(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll inverse(ll a, ll m) {
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = getMod(x, m);
    return res;
}

int main() {
    cin >> n;
    a.assign(n, 0);
    int cntNeg = 0;
    int cntZero = 0;
    int idxMaxNeg = -1;
    ll res = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            cntNeg++;
            res = getMod(res * (-a[i]), MOD);
            if (idxMaxNeg == -1 || a[idxMaxNeg] < a[i]) {
                idxMaxNeg = i;
            }
        } else if (a[i] == 0) {
            cntZero++;
        } else {
            res = getMod(res * a[i], MOD);
        }
    }

    if (cntZero > 1) {
        cout << 0;
        return 0;
    }

    if (cntNeg % 2 == 1) {
        if (cntZero != 0) {
            cout << 0;
        } else {
            cout << getMod(res * inverse(-a[idxMaxNeg], MOD), MOD);
        }
    } else {
        cout << res << endl;
    }
}