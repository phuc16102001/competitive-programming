#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a, b;

void solve() {
    int n;
    cin >> n;

    a.assign(n, 0);
    b.assign(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    
    multiset<ll> mst; //Sorted
    ll s = 0;
    ll left = 0;
    for (int i=0;i<n;i++) {
        mst.insert(a[i]+s);
        s += b[i];
        left = 0;
        while (mst.size() && *mst.begin()<s) {
            ll val = *mst.begin(); //Smallest
            left += (val - (s-b[i]));
            mst.erase(mst.begin());
        }
        cout << mst.size()*b[i] + left << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}