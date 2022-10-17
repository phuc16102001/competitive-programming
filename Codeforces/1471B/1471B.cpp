#include <iostream>
using namespace std;

void solve(){
    int n, x, a[200000];
    cin >> n >> x;

    long long result = 0;
    int times = 1;
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }

    while (true) {
        for (int i = 0; i < n; i++) {
            if (a[i] % x == 0) {
                result += a[i] * times;
                a[i] /= 2;
            }
            else {
                cout << result << endl;
                return;
            }
        }
        times *= 2;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}