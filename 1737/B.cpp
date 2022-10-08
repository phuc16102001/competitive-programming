#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define forf(i,a,b) for (int i=a;i<=b;i++)
#define forb(i,a,b) for (int i=a;i>=b;i--)

ll l, r;

void solve() {
    cin >> l >> r;
    ll cl = ceil(sqrtl(l));
    ll cr = ceil(sqrtl(r));
    ll fl = floor(sqrtl(l));
    ll fr = floor(sqrtl(r));
    ll cnt = (fr-cl)*3;
    if (fl!=cl){
        for (ll i=0;i<=2;i++) {
            if (l<=fl*(fl+i)) cnt++;
        }
    }
    for (ll i=0;i<=2;i++) {
        if (fr*(fr+i)<=r) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}