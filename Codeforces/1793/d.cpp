#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }

    vector<int> fa(n+1, 0), fb(n+1, 0);
    for (int i=0;i<n;i++) {
        fa[a[i]] = i;
        fb[b[i]] = i;
    }
    vector<int> x(2, 0);
    ll total = 0;
    ll t;

    int t1 = min(fa[1], fb[1]);
    int t2 = max(fa[1], fb[1]);
    int t3 = n-1;
    
    if (t1!=t2){
        t = t1;
        total += (t*(t+1))/2;
        t = t2-t1-1;
        total += (t*(t+1))/2;
        t = t3-t2;
        total += (t*(t+1))/2;
    } else {
        t = t1;
        total += (t*(t+1))/2;
        t = t3-t2;
        total += (t*(t+1))/2;
    }

    for (int i=2;i<=n;i++) {
        int r = i-1;
        int m1 = min(fa[r], fb[r]);
        int m2 = max(fa[r], fb[r]);
        if (i==2) {
            x[0] = m1;
            x[1] = m2;
        } else {
            x[0] = min(x[0],m1);
            x[1] = max(x[1],m2);
        }

        if ((x[0]<=fa[i] and fa[i]<=x[1]) or (x[0]<=fb[i] and fb[i]<=x[1])){
            continue;
        }

        ll left = 0;
        ll right = 0;
        ll ma, mb;
        ma = min(fa[i], fb[i]);
        mb = max(fa[i], fb[i]);
        if (mb<x[0]) {
            left = x[0]-mb-1;
            right = (n-1)-x[1];
        } else
        if (x[1]<ma) {
            left = x[0];
            right = ma-x[1]-1;
        } else {
            left = x[0]-ma-1;
            right = mb-x[1]-1;
        }
        total += (left*right)+(left)+(right)+1;
    }
    cout << total+1 << endl;
}