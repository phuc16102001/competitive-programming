#include <iostream>
using namespace std;

void solve(){
    bool result = true;
    int n,x;
    cin >> n >> x;
    int a[1000];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        int k;
        cin >> k;
        a[n-1-i]+=k;
        if (a[n-1-i]>x) result = false;
    }
    if (result) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}