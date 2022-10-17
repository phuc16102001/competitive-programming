#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define forf(i,a,b) for(int i=a;i<=b;i++)
#define forb(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define min(a,b) (a>b?b:a)
#define pb push_back

void solve() {
    int n, k;
    cin >> n >> k;
    vi s(k), a(k);
    forf(i,0,k-1) cin >> s[i];

    int t;
    forb(i,k-1,1) {
        a[i] = s[i]-s[i-1];
        if (i<k-1 && a[i]>a[i+1]) {
            cout << "No\n";
            return;
        }
    }

    ll d = n-k+1;
    if (k==1) {
        cout << "Yes\n";
        return;
    }
    ll maxSum = d*a[1];
    if (s[0]>maxSum) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--)solve();
}