
#include <iostream>
using namespace std;
 
void solve() {
    int n,a[10000],count=0;
    bool isOne = false;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        count+=a[i];
        if (a[i]==1) isOne = true;
    }
    if (count%2==0) {
        int each = count/2;
        if (each % 2 == 1) {
            if (isOne) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "YES\n";
        }
    } else {
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}