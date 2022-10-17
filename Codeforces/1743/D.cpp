#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<int> avail;

    int idx = 0;
    while (s[idx] == '0') idx++;
    s = s.substr(min(n - 1, idx));
    n = s.length();

    for (int i = 1; i <= n; i++) {
        avail.insert(i);
    }

    string res = s;
    int cnt = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            vector<int> toRemove;
            for (auto it = avail.rbegin(); it != avail.rend(); it++) {
                if (((i - *it) < 0) || (s[i - *it] == '0')) {
                    toRemove.push_back(*it);
                }
            }
            if (cnt - toRemove.size() > 0) {
                cnt -= toRemove.size();
                for (int i = 0; i < toRemove.size(); i++) {
                    avail.erase(toRemove[i]);
                }
                res[i] = '1';
            }
        }
    }

    idx = 0;
    while (res[idx] == '0') idx++;
    cout << res.substr(min(n - 1, idx)) << endl;
}

int main() {
    solve();
}