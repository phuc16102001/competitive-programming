#include<iostream>
using namespace std;

long long n;

void solve(){
    cin >> n;
    while ((n&1)==0){
        n >>= 1;
    }

    if (n==1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}