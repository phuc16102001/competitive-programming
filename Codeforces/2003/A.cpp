#include<iostream>
#include<algorithm>
using namespace std;

#define pb push_back
#define ll long long 
#define fi first
#define se second

void solve() {
    int n;
    string s;
    cin >> n >> s;
    cout << ((s[0] == s[n-1]) ? "NO\n" : "YES\n");
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}