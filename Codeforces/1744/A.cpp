#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<char> f;
string s;

void solve() {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;

    f.assign(50, 0);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (f[a[i] - 1] == 0) {
            f[a[i] - 1] = c;
        } else {
            if (f[a[i] - 1] != c) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}