#include<iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s=="abc" || s=="acb" || s=="bac" || s=="cba") {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}