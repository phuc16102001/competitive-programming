#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define pb push_back

int n, m, cnt;
vector<ll> f;
vector<vi> edges;
vector<bool> visited;
ll res;

ll getMod(ll a, ll m) {
    while (a < 0) a += m;
    return a % m;
}

void preprocess(ll n) {
    f.assign(n+1, 1);
    for (ll i = 2; i <= n; i++) {
        f[i] = getMod(f[i - 1] * i, MOD);
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    cnt = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto next : edges[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
}

int main() {
    preprocess(100000);
    cin >> n >> m;
    edges.assign(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    res = 0;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
            if (cnt > 2) {
                res = getMod(res + f[cnt], MOD);
            }
        }
    }
    cout << res;

    return 0;
}