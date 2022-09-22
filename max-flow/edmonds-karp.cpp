#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

#define INF 9999999
#define si set<int>

vector<si> e;
int n, m, s, t;
int c[1002][1002];
int f[1002][1002];
bool visit[1002];
int trace[1002];
int maxFlow = 0;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visit[u] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto it = e[cur].begin(); it!=e[cur].end();it++){
            int next = *it;
            if (c[cur][next]-f[cur][next]>0 && !visit[next]){
                trace[next] = cur;
                visit[next] = true;
                if (next==t) return;
                q.push(next);
            }
        }
    }
}

void findAug(){
    fill(trace+1, trace+n+1, -1);
    fill(visit+1, visit+n+1, false);
    bfs(s);
}

void increaseFlow() {
    int u = t;
    int minCapacity = INF;
    
    while (u!=s) {
        int prev = trace[u];
        minCapacity = min(minCapacity, c[prev][u]-f[prev][u]);
        u = prev;
    }

    u = t;
    while (u!=s) {
        int prev = trace[u];
        f[prev][u] += minCapacity;
        f[u][prev] -= minCapacity;

        if (c[prev][u]-f[prev][u] > 0) {
            e[prev].insert(u);
        } else {
            e[prev].erase(u);
        }

        if (c[u][prev]-f[u][prev] > 0) {
            e[u].insert(prev);
        } else {
            e[u].erase(prev);
        }

        u = prev;
    }

    maxFlow += minCapacity;
}

int main() {
    cin >> n >> m >> s >> t;
    e.resize(n+1);
    for (int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
        e[u].insert(v);
    }

    do {
        findAug();
        // cout << endl;
        // for (int i=1;i<=n;i++) {
        //     cout << i << " " << trace[i] << endl;
        // }
        if (trace[t]!=-1){
            increaseFlow();
        }
    } while (trace[t]!=-1);
    cout << maxFlow;
}