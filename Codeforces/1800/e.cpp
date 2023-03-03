#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

bool solve() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;
    vector<int> cnt(27, 0);
    if (n<=k) return a==b;
    for (int i=0;i<=n;i++) {
        if (i-k<0 and i+k>=n) {
            if (a[i]!=b[i]) return false;
        }
    }
    for (int i = 0; i < n; i++) {
        cnt[a[i] - 'a']++;
        cnt[b[i] - 'a']--;
    }
    for (int i = 0; i <= 26; i++) {
        if (cnt[i] != 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}