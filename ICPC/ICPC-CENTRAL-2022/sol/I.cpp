#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int, int>

vector<int> tmp(5, 0);
vector<int> a;
vector<ll> d(5, 0);
ll cnt = 0;

vector<vector<ll>> pascal;

void preprocess(int n) {
    pascal.assign(n + 1, vector<ll>(4, 0));
    for (int i = 1; i <= n; i++) {
        pascal[i][0] = 1;
        // cout << pascal[i][0] << " ";
        for (int j = 1; j < 4; j++) {
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            // cout << pascal[i][j] << " ";
        }
        // cout << endl;
    }
}

// a>=b
// ll C(ll a, ll b) {
//     return (f[a] / (f[b] * f[a - b]));
// }

int main() {
    preprocess(100001);
    int n;
    cin >> n;
    a.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i] % 5]++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            for (int k = j; k < 5; k++) {
                if ((i + j + k) % 5 != 0) continue;
                tmp.assign(5, 0);
                tmp[i]++;
                tmp[j]++;
                tmp[k]++;
                ll prod = 1;
                for (int x = 0; x < 5; x++) {
                    if (tmp[x]) {
                        ll nChoice = pascal[d[x]+1][tmp[x]];
                        // cout << d[x] << " " << tmp[x] << " " << nChoice << endl;
                        prod = prod * nChoice;
                    }
                }
                // if (prod) {
                //     cout << i << " " << j << " " << k << " " << prod << endl;
                // }
                cnt += prod;
            }
        }
    }
    cout << cnt;
}