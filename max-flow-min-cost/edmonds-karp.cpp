#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define vi vector<int>
#define MAXN 10002
#define INF 1<<29

int n, m, source, sink;
vector<vi> adj;       // Adjacency linked list
vector<vi> cost;      // Cost matrix
vector<vi> capacity;  // Capacity matrix
vector<int> degIn;      // Degree in
vector<int> degOut;     // Degree out
fstream fin, fout;

int totalFlow = 0;
int totalCost = 0;

void bellman(int source, vector<int>& distance, vector<int>& trace) {
    queue<int> q;
    vector<bool> inQueue(n+1, false);
    
    distance.assign(n+1, INF);
    trace.assign(n+1, -1);

    distance[source] = 0;
    q.push(source);
    inQueue[source] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        inQueue[cur] = false;
        for (int next: adj[cur]) {
            if (capacity[cur][next] > 0 && distance[next] > distance[cur]+cost[cur][next]) {
                distance[next] = distance[cur] + cost[cur][next];
                trace[next] = cur;
                if (!inQueue[next]) {
                    inQueue[next] = true;
                    q.push(next);
                }
            }
        }
    }
}

void increaseFlow(vector<int> distance, vector<int> trace) {
    int minCapacity = INF;
    int cur = sink;

    while (cur != source) {
        int prev = trace[cur];
        if (minCapacity > capacity[prev][cur]) {
            minCapacity = capacity[prev][cur];
        }
        cur = prev;
    }

    totalCost += minCapacity * distance[sink];
    totalFlow += minCapacity;

    cur = sink;
    while (cur != source) {
        int prev = trace[cur];
        capacity[prev][cur] -= minCapacity;
        capacity[cur][prev] += minCapacity;
        cur = prev;
    }
}

int main() {
    fin.open("LOGISTIC.INP",ios::in);
    fout.open("LOGISTIC.OUT",ios::out);

    // Input
    fin >> n >> m;
    capacity.assign(n+1, vi(n+1, 0));
    cost.assign(n+1, vi(n+1, 0));
    adj.assign(n+1, vi());
    degIn.assign(n+1, 0);
    degOut.assign(n+1, 0);

    for (int i=0;i<m;i++) {
        int u, v, c, w;
        fin >> u >> v >> c >> w;

        // Only adjacency, check movable using capacity
        adj[u].push_back(v);
        adj[v].push_back(u);

        degIn[v]++;
        degOut[u]++;
        capacity[u][v] = c;
        cost[u][v] = w;
        cost[v][u] = -w;
    }

    // Create source vertex
    for (int i=1;i<=n;i++){
        if (degIn[i] == 0) {
            adj[0].push_back(i);
            adj[i].push_back(0);
            capacity[0][i] = INF;
        }
        if (degOut[i] == 0){
            sink = i;
        }
    }
    source = 0;

    // Solution
    vector<int> distance, trace;
    do {
        bellman(source, distance, trace);
        if (trace[sink] == -1) {
            break;
        }
        increaseFlow(distance, trace);
    } while (trace[sink] != -1);
    
    fout << totalFlow << endl << totalCost;
    fin.close();
    fout.close();
}