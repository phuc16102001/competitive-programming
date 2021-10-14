#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd (ll n1, ll n2) {
    ll tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

void solve() {
    int n;
    vector<ll> a;
    cin >> n;
    ll m;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        if (i==0 || (i>0 && m>t)) {
            m=t;
        } 
        a.push_back(t);
    }
    for (int i=0;i<n;i++) {
        a[i] -= m;
    }
    int i;
    for (i=0;i<n;i++){
        if (a[i]!=0) {
            break;
        }
    }
    if (i==n) {
        cout << "-1\n";
        return;
    }

    long res = a[i];
    while (i<n) {
        if (a[i]!=0) {
            res = gcd(res,a[i]);
        }
        i++;
    }
    cout << res << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}