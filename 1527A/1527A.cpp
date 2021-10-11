#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int nBit = floor(log2(n))+1;
    cout << (1<<(nBit-1))-1 << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}