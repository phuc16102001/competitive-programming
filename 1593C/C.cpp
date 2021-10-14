#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    vector<int> a;
    cin >> n >> k;
    for (int i=0;i<k;i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    int i = k-1;
    long long s = 0;
    int count = 0;
    while (i>=0 && s<a[i]) {
        s+=n-a[i];
        i--;
        count++;
    }
    cout << count << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}