#include <iostream>
using namespace std;

void solve() {
    int n,a[200001];
    cin >> n;
    for (int i=0;i<n;cin>>a[i++]);

    int level = 1;
    int oldChild = 1;
    int child = 0;
    for (int i=1;i<n;i++){
        // cout << i << " " << level << " " << oldChild << " " << child << endl;
        if (a[i]<a[i-1]) {
            oldChild--;
        }
        if (oldChild==0) {
            level++;
            oldChild = child;
            child = 0;
        }
        child++;
    }
    cout << level << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}