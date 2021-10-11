#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c;
    cin >> s;
    int idx = -1;
    bool same = true;
    for (int i=0;i<s.length();i++) {
        if (s[i]!=c) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << "0\n";
        return;
    } 
    for (int i=s.length()-1;i>=0;i--) {
        if (s[i]==c) {
            idx = i+1;
            break;
        }
    }
    if (idx>n/2) {
        cout << "1" << endl << idx << endl;
    } else {
        cout << "2" << endl << n << " " << n-1 << endl;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}