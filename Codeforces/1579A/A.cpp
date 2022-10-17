#include <bits/stdc++.h>
using namespace std;

void solve() {
    int count[3] = {0};
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        count[s[i]-'A']++;
    }
    cout << (count[0]+count[2]==count[1]?"YES":"NO") << '\n';
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}