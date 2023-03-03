#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

ll ret = 0;

void solve() {
    int n;
    cin >> n;

    priority_queue<int> q;
    ret = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            if (q.size()>0){
                ret += q.top();
                q.pop();
            }
        } else {
            q.push(t);
        }
    }

    cout << ret << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}