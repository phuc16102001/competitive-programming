#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int t;
    cin >> n;
    for (int i=0;i<n;i++) cin >> t;
    int other = 10-n;
    cout << 3*(other*(other-1)) << endl;
}

int main(){
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}