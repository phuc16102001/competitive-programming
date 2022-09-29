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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(i,0,n-1) {
        cin >> a[i];
    }
    int tmp = a[0];
    for(i,1,n-1) {
        int t1 = tmp-a[i];
        int t2 = tmp+a[i];
        if (t1!=t2 && t1>=0 && t1>=0 ) {
            cout <<"-1\n";
            return;
        } else {
            if (tmp-a[i]>=0) {
                tmp -= a[i];
            } else {
                tmp += a[i];
            }
        }
    }
    cout << a[0] << " ";
    tmp = a[0];
    for(i,1,n-1){
        if (tmp-a[i]>=0) {
            tmp -= a[i];
        } else {
            tmp += a[i];
        }
        cout << tmp << " ";
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}