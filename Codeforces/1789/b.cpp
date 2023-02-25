#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pii pair<int, int>

int abs(int x) {
    if (x<0) return -x;
    return x;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> isFlip;
    for (int i=0;i<n/2;i++) {
        if (s[i]!=s[n-1-i]) {
            isFlip.push_back(1);
        } else {
            isFlip.push_back(0);
        }
    }
    bool first = false;
    bool second = false;
    bool third = false;
    for (int i=0;i<isFlip.size();i++) {
        if (isFlip[i]==1) {
            if (!first) first=true;
            if (first && second && !third) third = true;
        } else {
            if (first && !second) second = true;
        }
        
    }
    if (third) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}