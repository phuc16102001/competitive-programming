#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<sstream>
using namespace std;

#define pb push_back
#define ll long long 
#define pll pair<long long, long long>
#define fi first
#define se second

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>());
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        a[i].assign(t, 0);
        for (int j=0;j<t;j++) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        // for (int x:a[i]) cout << x << " ";
        // cout << endl;
    }
    vector<pll> edges(n, pll());
    ll maxSecond = -1;
    for (int i=0;i<n;i++) {
        ll first = -1;
        ll second = -1;
        int cur = 0;
        int j = 0;
        while (j<a[i].size()) {
            // cout << "DEBUG: " << a[i][j] << " " << cur << endl;
            if (a[i][j] == cur - 1) { j++; continue; }
            if (a[i][j] == cur) { cur++; j++; continue; }
            if (first != -1) {
                second = cur;
                break;
            }
            first = cur;
            cur++;
        }
        if (first != -1 && second == -1) {
            second = a[i][a[i].size()-1]+1;
        }
        if (first == -1) {
            edges[i] = {a[i][a[i].size()-1]+1,a[i][a[i].size()-1]+2};
        } else {
            edges[i] = {first, second};
        }
        maxSecond = max(maxSecond, (ll)edges[i].se);
        // cout << edges[i].fi << " " << edges[i].se << endl;
    }
    
    ll res = 0;
    if (maxSecond <= m) {
        res = (maxSecond * (maxSecond+1)) + (m*(m+1)/2) - (maxSecond*(maxSecond+1)/2);
    } else {
        res = (maxSecond * (m+1));
    }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}