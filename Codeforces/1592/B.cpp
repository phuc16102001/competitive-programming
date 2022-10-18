#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a, b;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        a.push_back(t);
        b.push_back(t);
    }
    sort(b.begin(),b.end());
    // bool sorted = true;
    // for (int i=0;i<n;i++) {
    //     if (a[i].second!=i) {
    //         sorted = false;
    //         break;
    //     }
    // }
    for (int i=n-x;i<x;i++) {
        if (a[i]!=b[i]){
            cout << "NO\n";
            return;
        }
    }
    // if (!sorted) {
    //     for (int i=0;i<n;i++) {
    //         bool c1 = abs(a[i].second-i)>=x;
    //         bool c2 = (min(i,a[i].second)-x)>=0;
    //         bool c3 = (max(i,a[i].second)+x)<n;
    //         if (!c1 && !c2 && !c3) {
    //             cout << "NO\n";
    //             return;
    //         }
    //         a[a[i].second].second=a[i].second;
    //     }
    // }
    cout << "YES\n";
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}