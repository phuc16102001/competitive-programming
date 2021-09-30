#include <iostream>
using namespace std;

void solve() {
    long long n, m, k;    
    cin >> n >> m >> k;
    long long x1 = n-1;
    long long x2 = n*(n-1)/2; 
    long long d = -1;
    
    if (m>x2 || m < x1) {
        d = -1;
    } else
    if (n==1) {
        d = 0;
    } else
    if (m==x2) {
        d = 1;
    } else {
        d = 2;
    } 
    
    if (d!=-1 && d<k-1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}
