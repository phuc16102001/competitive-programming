#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>

ll c, ret;

using namespace std;

ll calculateSeg(vi a, int l, int r) {
    ret = (r-l+1);
    for (int i=l;i<=r;i++){
        if (a[i]==0){
            ret++;
        }
    }
    return ret;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    c = 0;
    for (int l=0;l<n;l++){
        for (int r=l;r<n;r++){
            c+=calculateSeg(a,l,r);
        }
    }
    cout << c << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}