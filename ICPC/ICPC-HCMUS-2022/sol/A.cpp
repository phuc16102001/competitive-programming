#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 1e6
#define pi pair<int, int>
#define vi vector<int>
#define fi first
#define se second

int n, m;
vector<vi> edges;
vector<int> dist;

int dijkstra(int source, int terminal) {
    dist.assign(n+1, INF);
    priority_queue<pi, vector<pi>, greater<pi>> q;

    dist[source] = 0;
    q.push({0, source});
    while (!q.empty()) {
        int node = q.top().se;
        q.pop();
        for (int next: edges[node]) {
            if (dist[next]>dist[node] + 1) {
                dist[next]=dist[node] + 1;
                if (next==terminal) return dist[terminal];
                q.push({dist[next], next});
            }
        }
    }
    return dist[terminal];
}

int main() {
    cin >> n >> m;
    edges.assign(n+1, vector<int>());
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    cout << dijkstra(1, n) - 1;
}