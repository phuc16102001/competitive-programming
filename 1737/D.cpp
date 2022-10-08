#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define INF 1e9
#define INFL 1e18

vector<vi> edges;
vector<vi> weight;
int n, m;

void ford(int source, vector<int>& dist, vector<int>& trace) {
    queue<int> q;
    vector<bool> isInQueue(n+1, false);

    q.push(source);
    isInQueue[source] = true;
    dist[source] = 0;
    while (q.size()) {
        int node = q.front();
        q.pop();
        isInQueue[node] = false;

        for (int next:edges[node]) {
            if (dist[next]>dist[node]+1) {
                dist[next] = dist[node]+1;
                trace[next] = node; 
                if (!isInQueue[next]) {
                    isInQueue[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

void floyd(vector<vi>& dist, vector<vi>& next) {
    for (int node=1;node<=n;node++) {
        for (int element: edges[node]) {
            dist[node][element] = 1;
        }
    }
    for (int node=1;node<=n;node++) {
        dist[node][node]=0;
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dist[i][j]>dist[i][k]+dist[k][j]) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    edges.assign(n+1, vector<int>());
    weight.assign(n+1, vector<int>(n+1, 0));

    for (int i=0;i<m;i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].pb(v);
        edges[v].pb(u);
        if (weight[u][v]==0){
            weight[u][v] = c;
            weight[v][u] = c;
        } else {
            weight[u][v] = min(weight[u][v],c);
            weight[v][u] = min(weight[v][u],c);
        }
    }

    vector<vi> dist(n+1, vector<int>(n+1,INF));
    vector<vi> next(n+1, vector<int>(n+1,-1));
    floyd(dist, next);

    ll res = INFL;
    for (int node=1;node<=n;node++){
        for (int next: edges[node]) {
            if (next>node) {
                for (int vertex=1;vertex<=n;vertex++){
                    ll dx = min(dist[node][vertex], dist[next][vertex]) + 1 + dist[vertex][1] + dist[vertex][n];
                    ll dy = min(dist[node][1]+dist[next][n],dist[node][n]+dist[next][1]);
                    ll cost = weight[node][next]*(1+min(dx,dy));
                    if (cost<res) res = cost;
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}