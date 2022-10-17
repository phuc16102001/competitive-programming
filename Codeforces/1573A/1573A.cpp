#include <bits/stdc++.h>
using namespace std;

#define fast cin.tie(0);ios_base::sync_with_stdio(0);

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='0') {
            n -= 1;
        } else {
            n += int(s[i])-48;
        }
    }
    if (s[s.length()-1]!='0') {
        n -= 1;
    }
    cout << n << endl;
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while(nTest--) {
        solve();
    }
}