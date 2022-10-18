#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[15],b[15];
int m,n,s0;
bool vis[10000005];
int d[10000005];

void bfs(int u) {
    queue<int> q;
    q.push(u); vis[u] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < n; i++) {
            int cur = (((u%m)*(a[i]%m)%m)+b[i]%m)%m;
            if (!vis[cur]) {
                q.push(cur);
                vis[cur] = true;
                d[cur] = d[u]+1;
            }
        }
    }
}

signed main() {
    cin >> m >> n >> s0;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    bfs(s0);
    if (vis[0]) cout << d[0];
    else cout << -1;
    return 0;
}
