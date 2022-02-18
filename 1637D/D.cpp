#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 102
#define ll long long
#define vi vector<int>
#define INF 1e18-1

int sum_sqr;
int sum;
bitset<MAXN*MAXN> bit;
ll ret, new_ret;

int sqr(int x){
    return x*x;
}

void solve() {
    int n;
    cin >> n;
    
    vi a(n), b(n);

    sum_sqr = 0;
    sum = 0;
    ret = INF;
    bit=1;
    for (int i=0;i<n;i++){
        cin >> a[i];
        sum_sqr += a[i]*a[i];
        sum += a[i];
    }
    for (int i=0;i<n;i++){
        cin >> b[i];
        sum_sqr += b[i]*b[i];
        sum += b[i];
    }
    sum_sqr = (n-2)*sum_sqr;

    // result = sqr[sum(a)]+sqr[sum(b)]+(n-2)[sum(a.a)+sum(b.b)]

    for (int i=0;i<n;i++){
        bit = (bit<<a[i]) | (bit<<b[i]);
    }

    for (int i=0;i<=sum;i++) {
        if (bit[i]) {
            new_ret = sum_sqr + sqr(i) + sqr(sum-i);
            if (ret>new_ret) {
                ret = new_ret;
            }
        }
    }
    cout << ret << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}