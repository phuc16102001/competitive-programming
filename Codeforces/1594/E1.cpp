#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;

ll p(ll a, ll b) {
    if (b==0) {
        return 1;
    }
    ll t = p(a,b/2)%MOD;
    if (b%2==0) {
        return (t*t)%MOD;
    } else {
        return (a*(t*t)%MOD)%MOD;
    }
}

int main() {
    ll n, s=6;
    cin >> n;
    ll node = 1;
    for (ll i=0;i<n;i++) {
        node*=2;
    }
    node -= 1;
    s = (s * p(4,node-1))%MOD;
    cout << s << endl;
}

