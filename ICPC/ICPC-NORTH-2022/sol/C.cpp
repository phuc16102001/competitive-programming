#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

vector<pi> a;
vector<vi> edges;
vector<int> trace, matchX, matchY;
int n, cnt;

float distance(pi a, pi b) {
    float dx = a.fi - b.fi;
    float dy = a.se - b.se;
    return sqrt(dx * dx + dy * dy);
}

bool isInX(pi point) {
    return (point.fi + point.se) % 2;
}

int findAug() {
    trace.assign(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (isInX(a[i]) && matchX[i] == -1) {
            q.push(i);
        }
    }

    // BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : edges[node]) {
            if (!isInX(a[next]) && trace[next] == -1) {
                // To Y and not visit
                trace[next] = node;
                if (matchY[next] == -1) {
                    // Not matched
                    return next;
                }

                // Push next X (matchY of next) to queue
                q.push(matchY[next]);
            }
        }
    }
    return -1;  // Path not found
}

void extendPath(int node) {
    while (node != -1) {
        int prev = trace[node];
        int next = matchX[prev];
        matchX[prev] = node;
        matchY[node] = prev;
        node = next;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n) {
        // Input
        a.assign(n, {0, 0});
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            a[i] = {x, y};
        }

        // Create graph
        edges.assign(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && distance(a[i], a[j]) <= 1.3) {
                    edges[i].pb(j);
                }
            }
        }

        // Find maximum matching pairs
        matchX.assign(n, -1);
        matchY.assign(n, -1);
        cnt = 0;
        int lastNode;
        do {
            lastNode = findAug();
            if (lastNode != -1) {
                extendPath(lastNode);
                cnt++;
            }
        } while (lastNode != -1);

        // Result
        cout << n - cnt << endl;
    }
    return 0;
}