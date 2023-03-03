#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

bool solve() {
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        s[i] = tolower(s[i]);
        if (cnt == 0) {
            if (s[i] != 'm')
                return false;
            else
                cnt++;
        } else if (cnt == 1) {
            if (s[i] != 'm' && s[i] != 'e')
                return false;
            else if (s[i] == 'e')
                cnt++;
        } else if (cnt == 2) {
            if (s[i] != 'e' && s[i] != 'o')
                return false;
            else if (s[i] == 'o')
                cnt++;
        } else if (cnt == 3) {
            if (s[i] != 'o' && s[i] != 'w')
                return false;
            else if (s[i] == 'w')
                cnt++;
        } else if (cnt == 4) {
            if (s[i] != 'w') return false;
        }
    }
    if (cnt == 4) {
        return true;
    } else {
        return false;   
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    };
}