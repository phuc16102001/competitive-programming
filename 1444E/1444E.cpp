#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int n;
bool a[101][101]={false};
bool check[101] = {false};

void test(int v) {
    for (int u=1;u<=n;u++){
        if (a[u][v] && !check[u]) {
            int x;
            cout << "? " << v << " " << u << endl;
            cout.flush();
            cin >> x;
            if (x==v) {
                check[u]=true;
            } else {
                check[v]=true;
                test(u);
                return;
            }
        }
    }
    if (!check[v]) {
        cout << "! " << v << endl;
        cout.flush();
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

vector<int> findPath(int s, int e) {
    queue<int> q;
    vector<int> trace(n+1,0);
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=1;i<=n;i++){
            if (a[u][i] && trace[i]==0) {
                trace[i]=u;
                q.push(i);
            }
        }
    }
    return trace;
}

int getStartVertex() {
    int maxDist, u, v;
    bfs(1,maxDist,u);
    cout << u << " " << v << " " << maxDist << endl;
    bfs(u,maxDist,v);
    cout << u << " " << v << " " << maxDist << endl;
    vector<int> path = findPath(u,v);
    for (int i=1;i<=n;i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    int move = maxDist/2;
    while (move--){
        v = path[v];
    }
    return v;
}

int main() {
    cin >> n;
    for (int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        a[x][y]=a[y][x]=true;
    }

    int startVertex = getStartVertex();
    cout << startVertex << endl;
    test(startVertex);
}