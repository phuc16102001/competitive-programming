#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    f--;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    int v = a[f];
    sort(a.begin(), a.end(), less<int>());
    // for (int x: a) cout << x << " ";
    // cout << endl;
    int upper = upper_bound(a.begin(), a.end(), v) - a.begin();
    int lower = lower_bound(a.begin(), a.end(), v) - a.begin();
    if (upper == n || a[upper] != v) upper--;
    cout << lower << " " << upper << endl;

    if (k >= n-lower) {
        cout << "YES\n";
    } else if (k < n-upper) {
        cout << "NO\n";
    } else {
        cout << "MAYBE\n";
    }

}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}