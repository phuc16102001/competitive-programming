#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n;
bool a[101][101]={false};
bool check[101] = {false};

vector<int> findPath(int s, int e, int& distance) {
    queue<int> q;
    vector<int> trace(n+1,0);
    vector<int> dist(n+1,0);
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=1;i<=n;i++){
            if (a[u][i] && trace[i]==0) {
                dist[i]=dist[u]+1;
                trace[i]=u;
                q.push(i);
            }
        }
    }
    distance = dist[e];
    return trace;
}

void test(int s, int e) {
    // for (int u=1;u<=n;u++){
    //     if (a[u][v] && !check[u]) {
    //         int x;
    //         cout << "? " << v << " " << u << endl;
    //         cout.flush();
    //         cin >> x;
    //         if (x==v) {
    //             check[u]=true;
    //         } else {
    //             check[v]=true;
    //             test(u);
    //             return;
    //         }
    //     }
    // }
    // if (!check[v]) {
    //     cout << "! " << v << endl;
    //     cout.flush();
    // }

    int distance;
    vector<int> path = findPath(s,e,distance);
    int moveBack = distance/2;
    while (moveBack--){
        e = path[e];
    }
    for (int i=1;i<=n;i++) {
        if (a[e][i] && !check[i]){
            int x;
            cout << "? " << e << " " << i << endl;
            cout.flush();
            cin >> x;
            if (x==e) {
                check[i]=true;
            } else {
                check[e]=true;
                test(u);
                return;
            }
        }
    }
}

void bfs(int root, int& maxDistance, int& endPoint){
    queue<int> q;
    int dist[101] = {0};
    q.push(root);

    while (!q.empty()){ 
        int u = q.front();
        q.pop();
        for (int i=1;i<=n;i++) {
            if (a[u][i] && dist[i]==0) {
                dist[i]=dist[u]+1;
                q.push(i);
            }
        }

    }

    endPoint = -1;
    maxDistance = 0;
    for (int i=1;i<=n;i++){
        if (dist[i]>maxDistance) {
            maxDistance = dist[i];
            endPoint=i;
        }
    }
}

int getVertex(int& start, int& end) {
    int dist, u, v;
    bfs(1,dist,u);
    bfs(u,dist,v);
    start = u;
    end = v;
}

int main() {
    cin >> n;
    for (int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        a[x][y]=a[y][x]=true;
    }

    int l, r;
    getVertex(l, r);
    test(l,r);
}