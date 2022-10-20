#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[15], b[15];
ll m, n, s0;
bool vis[10000005];
ll d[10000005];

ll getMod(ll a, ll m) {
    while (a < 0) a += m;
    return a % m;
}

void bfs(ll u) {
    queue<ll> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll i = 0; i < n; i++) {
            ll cur = getMod(getMod(u * a[i], m) + b[i], m);
            if (!vis[cur]) {
                q.push(cur);
                vis[cur] = true;
                d[cur] = d[u] + 1;
            }
        }
    }
}

signed main() {
    cin >> m >> n >> s0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    bfs(s0);
    if (vis[0]) {
        cout << d[0];
    } else {
        cout << -1;
    }
    return 0;
}
