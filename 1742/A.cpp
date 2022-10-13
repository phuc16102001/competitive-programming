#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

void solve() {  
    int a, b, c;
    cin >> a >> b >> c;
    int s = a+b+c;
    int m = max(a, max(b,c));
    if (m==s-m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}