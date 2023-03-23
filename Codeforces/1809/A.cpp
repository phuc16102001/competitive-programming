#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define fi first
#define se second
#define pb push_back

void solve() {
    string s;
    cin >> s;
    int c[10] = {0};
    int m = 0;
    for (int i=0;i<s.length();i++) {
        int x = s[i]-'0';
        c[x]++;
        m = max(m, c[x]);
    }
    if (m==1 || m==2) {
        cout << "4\n";
        return;
    }
    if (m==3) {
        cout << "6\n";
        return;
    }
    cout << "-1\n";
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        solve();
    }
}