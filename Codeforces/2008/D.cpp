#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> group, a, visited;
string s;
int groupCnt;

void bfs(int node, int assign, unordered_map<int, int>& mp) {
    queue<int> q;
    q.push(node);
    int cntBlack = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        group[cur] = assign;
        if (s[cur] == '0') cntBlack++;
        q.push(a[cur]-1);
    }
    mp[assign] = cntBlack;
}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    cin >> s;

    group.assign(n, -1);
    groupCnt = 0;
    visited.assign(n, false);
    unordered_map<int, int> mp;
    for (int i=0;i<n;i++) {
        // cout << i << " ";
        if (group[i] == -1) bfs(i, groupCnt++, mp);
    }

    for (int i=0;i<n;i++) {
        cout << mp[group[i]] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}