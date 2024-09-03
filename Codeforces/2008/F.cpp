#include<iostream>
#include<vector>
#define MODULO 1000000007
#define ll long long
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll inv(ll a) {
    int x, y;
    gcd(a, MODULO, x, y);
    x = (x % MODULO + MODULO) % MODULO;
    return x;
}

ll solve() {
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    ll numerator = 0;
    ll accSum = 0;
    ll tmp = 0;
    for (int i=1;i<n;i++) {
        accSum = (accSum + (a[i-1] % MODULO)) % MODULO;
        tmp = (accSum * a[i] % MODULO) % MODULO;
        numerator = (numerator + tmp) % MODULO;
    }
    tmp = (n % MODULO *(n-1) % MODULO) % MODULO;
    ll denominator = (tmp * inv(2)) % MODULO;
    return (numerator * inv(denominator)) % MODULO;
}

int main() {
    int n;
    cin >> n;
    while (n--) cout << solve() << endl;
}