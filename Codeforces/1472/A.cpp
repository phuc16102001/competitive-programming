#include <iostream>
using namespace std;
 
void solve(){
    int w,h,n,count = 1;
    cin >> w >> h >> n;
    while (w%2==0) {
        w/=2;
        count*=2;
    }
    while (h%2==0) {
        h/=2;
        count*=2;
    }
    if (count>=n) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
