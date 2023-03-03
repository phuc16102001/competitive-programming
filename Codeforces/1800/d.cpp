#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i=3;i<=s.length();i++) {
        int a = s[i-3];
        int b = s[i-1];
        if (a==b) cnt++;
    }
    cout << n-1-cnt << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}