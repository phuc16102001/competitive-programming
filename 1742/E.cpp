#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

vector<int> a;
vector<ll> sum;
vector<int> maxLeft;

void solve() {  
    int n, q;
    cin >> n >> q;
    a.assign(n, 0);
    sum.assign(n, 0);
    maxLeft.assign(n, 0);

    int vMax = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (i!=0) {
            sum[i] = sum[i-1]+a[i];
            vMax = max(vMax, a[i]);
        } else {
            vMax = a[i];
            sum[i] = a[i];
        }
        maxLeft[i] = vMax;
    }

    for (int i=0;i<q;i++) {
        int k;
        cin >> k;
        int idx = upper_bound(maxLeft.begin(), maxLeft.end(), k) - maxLeft.begin();
        
        if (idx==0) {
            cout << 0 << " ";
        } else {
            cout << sum[idx-1] << " ";
        }
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}