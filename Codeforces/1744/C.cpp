#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n;
string s;
char c;
vector<int> a;

void solve() {
    cin >> n >> c >> s;
    if (c=='g') {
        cout << 0 << endl;
        return;
    }
    a.clear();
    for (int i=0;i<s.length();i++){
        if (s[i]=='g') {
            a.pb(i);
        }
    }
    a.pb(a[0]+n);
    int res = 0;
    for (int i=0;i<s.length();i++){
        if (s[i]==c) {
            int idx = lower_bound(a.begin(), a.end(), i) - a.begin();
            res = max(res, a[idx]-i);
        }
    }
    cout << res << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
    return 0;
}