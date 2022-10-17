#include <iostream>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    if (r / 2 < l) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}