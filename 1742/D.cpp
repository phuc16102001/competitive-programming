#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

bool coprime[1001][1001];

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

void solve() {
    int n;
    int res = -1;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> have(1001, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        have[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1000; j >= 1; j--) {
            if (coprime[a[i]][j] && have[j]!=-1) {
                res = max(res, i + have[j] + 2);
            }
        }
    }
    cout << res << endl;
}

void preprocess() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = i; j <= 1000; j++) {
            coprime[i][j] = (gcd(i, j) == 1);
            coprime[j][i] = coprime[i][j];
        }
    }
}

int main() {
    preprocess();
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}