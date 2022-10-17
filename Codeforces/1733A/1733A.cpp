#include<iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[101];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    long long s=0;
    for (int i=0;i<k;i++){
        int mx = a[i];
        for (int j=i+k;j<n;j+=k){
            if (mx<a[j]){
                mx = a[j];
            }
        }
        s+=mx;
    }
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}