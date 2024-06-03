#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n;
    unordered_map<int, bool> otherMp;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
        otherMp[b[i]]=true;
    }
    cin >> m;
    vector<int> d(m);
    unordered_map<int, int> mp;
    for (int i=0;i<m;i++) {
        cin >> d[i];
        mp[d[i]]++;
    }

    for (int i=0;i<n;i++) {
        if (a[i] != b[i]) {
            if (mp[b[i]] == 0) {
                cout << "NO\n";
                return;
            }
            mp[b[i]]--;
        }
    }
    if (otherMp[d[n-1]]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}