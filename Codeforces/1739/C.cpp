#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353 

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define fi first
#define se second

int f[61];
ll a, b, x, y, t;

int gcd(ll a, ll b, ll &x, ll &y) {
    if (b==0){
        x = 1;
        y = 0;
        return a;
    }
    ll xt, yt;
    int res = gcd(b,a%b,xt,yt);
    x = yt;
    y = xt - (a/b)*yt;
    return res;
}

int inverse(ll a, ll m){
    ll x, y;
    int g = gcd(a,m,x,y);
    if (g != 1){
        cout << "ERR\n";        
        return -1;
    } 
    return (x%m+m)%m;
}

int c(ll a, ll b){
    ll c = (ll) f[a]*f[b-a] % MOD;
    ll denom = inverse(c,MOD);
    ll res = (f[b]*denom)%MOD;
    return res;
}

void dp() {
    f[0] = 1;
    for (int i=1;i<=60;i++) {
        int t = f[i-1];
        f[i]=0;
        for (int j=0;j<i;j++){
            f[i] = (f[i]%MOD + t%MOD)%MOD;
        }
    }

}

void solve() {
    int n;
    cin >> n;

    a = 1;
    b = 0;
    for (int i=4;i<=n;i+=2) {
        ll x = c(i/2-1,i-2);
        ll y = c(i/2-2,i-2);
        t = a;
        a=(x%MOD+y%MOD+b%MOD)%MOD;
        b=(t%MOD+y%MOD)%MOD;
    }
    cout << a << " " << b << " "<<  1 << endl;
}

int main() {
    dp();
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}