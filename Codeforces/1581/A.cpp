#include <bits/stdc++.h>
using namespace std;

const int modulo=1e9+7;

void solve() {
    int n;
    cin >> n;
    long long p = 1;
    for (int i=3;i<=2*n;i++){
        p=(p*i)%modulo;
    }
    cout << p << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}

