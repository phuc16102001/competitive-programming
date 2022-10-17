#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=n;j>(n-i);j--){
            cout << j << " ";
        }
        cout << 1 << " ";
        for (int j=(n-i);j>1;j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}