#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define for(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second

void solve() {
    int n, m;
    cin >> n >> m;
    if (n<4 || m<4) {
        cout << max(1,n-1) << " " << max(1,m-1) << endl;
    } else {
        cout << "1 1\n";
    }
}
int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}