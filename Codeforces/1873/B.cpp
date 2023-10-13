#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int p = 1;
    int cntZero = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (a[i]==0) {
            cntZero += 1;
        } else {
            p *= a[i];
        }
    }

    if (cntZero > 1) {
        cout << 0 << endl;
        return;
    } else if (cntZero == 1) {
        cout << p << endl;
        return;
    }

    int minValue = a[0];
    for (int i=1;i<n;i++) {
        if (minValue > a[i]) {
            minValue = a[i];
        }
    }
    cout << p + p/minValue << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}