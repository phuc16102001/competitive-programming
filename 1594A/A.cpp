#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    long long n;
    cin >> n;
    cout << -(n-1) << " " << n << endl;
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}