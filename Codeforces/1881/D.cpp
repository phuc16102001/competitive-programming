#include<iostream>
#include<set>
#include<vector>
#include <cmath>
#include<unordered_map> 
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    unordered_map<int, int> cnt;
    for (int i=0;i<n;i++) {
        while (a[i]%2==0) {
            a[i]/=2;
            if (cnt.find(2)==cnt.end()) {
                cnt[2] = 1;
            } else {
                cnt[2]++;
            }
        }
        for (int k=3;k<=sqrt(a[i]);k+=2) {
            while (a[i]%k==0) {
                if (cnt.find(k)==cnt.end()) {
                    cnt[k] = 1;
                } else {
                    cnt[k]++;
                }
                a[i] /= k;
            }
        }
        if (a[i]>2) {
            if (cnt.find(a[i])==cnt.end()) {
                cnt[a[i]]=1;
            } else {
                cnt[a[i]]++;
            }
        }
    }
    for (auto it:cnt) {
        if (it.second % n !=0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}