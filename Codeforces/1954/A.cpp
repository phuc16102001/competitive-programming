#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int m = a-max(floor(a*1.0/b), ceil(a*1.0/b));
    if (m<=c) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}