#include<iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int cnt[51] = {0};
    int res = 0;
    for (int i=0;i<n;i++) {
        int l, r;
        cin >> l >> r;
        if (l<=k and k<=r) 
        for (int j=l;j<=r;j++) cnt[j]++;
    }
    for (int i=1; i<=50;i++) {
        if (cnt[i]==cnt[k]) {
            res++;
        }
    }
    if (res==1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--)solve();
}