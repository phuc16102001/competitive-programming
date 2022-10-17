#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define for(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define min(a,b) (a>b?b:a)

void solve() {
    ll sum = 0;
    int n;
    cin >> n;
    vi a(n), b, c;
    int ca = 0;
    int cb = 0;
    int m = 0;
    for(i,0,n-1) {
        cin >> a[i];
        if (a[i]) ca++; else cb++;
    }
    for(i,0,n-1) {
        int t;
        cin >> t;
        sum += t;
        if (a[i]) b.push_back(t); else c.push_back(t);
        if (i==0 || t<m) m=t;
    }
    sum *= 2;

    if (ca>cb) {
        sort(b.begin(), b.end());
        for (i,0,min(b.size(),abs(ca-cb)-1)) sum -= b[i];
    } else if (ca==cb) {
        sum -= m;
    } else {
        sort(c.begin(), c.end());
        for (i,0,min(c.size(),abs(ca-cb)-1)) sum -= c[i];
    }
    cout << sum << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--)solve();
}