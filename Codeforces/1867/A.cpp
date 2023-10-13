#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector< pair<int, int> > a;
    a.assign(n, make_pair(0, 0));

    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        a[i] = make_pair(t, i);
    }
    sort(a.begin(), a.end());
    vector<int> b(n, 0);
    for (int i=0;i<n;i++) {
        b[a[i].second] = (n-i);
    }
    for (int i=0;i<n;i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}