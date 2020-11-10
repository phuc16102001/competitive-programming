#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i=4*n;n>0;i-=2){
        cout << i << " ";
        n--;       
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}