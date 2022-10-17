#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << 1 << " ";
    for (int i=n;i>=2;i--) {
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}