#include<iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.length()==1) {
        cout << "NO\n";
        return;
    }

    for (int i=0;i<s.length();i++) {
        if (s[0] != s[i]) {
            swap(s[0], s[i]);
            cout << "YES\n" << s << endl;
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}