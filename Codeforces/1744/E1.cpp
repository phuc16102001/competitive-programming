#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<ll> prime, smallestPrime;
vector<bool> isPrime;

void sieve(int n) {
    isPrime.assign(n + 1, true);
    smallestPrime.assign(n + 1, 1);
    prime.clear();
    isPrime[0] = false;
    isPrime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime.pb(i);
            smallestPrime[i] = i;
            for (ll j = i * i; j <= n; j += i) {
                isPrime[j] = false;
                smallestPrime[j] = i;
            }
        }
    }
}

vector<ll> parseComponent(ll x) {
    vector<ll> component;
    while (x > 1) {
        ll factor = smallestPrime[x];
        x /= factor;
        component.pb(factor);
    }
    return component;
}

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int x = a + 1; x <= c; x++) {
        vector<ll> px = parseComponent(x);
        ll minY = a * b;
        for (int i = 0; i < px.size(); i++) {
            if (minY % px[i] == 0) {
                minY /= px[i];
            }
        }
        if (b < minY && minY <= d) {
            cout << x << " " << minY << endl;
            return;
        }
        ll ly = b / minY;
        ll ry = d / minY;
        if (ly + 1 <= ry) {
            cout << x << " " << (ly + 1) * minY << endl;
            return;
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main() {
    sieve(100000);
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}