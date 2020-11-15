#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << n-1 << endl;
    for (int i=2;i<=n;i++){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}