#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int cnt = 1;
    for (int i=1;i<n;i++){
        if (a[i]!=a[i-1]) {
            cnt++;
        }
    }
    for (int i=1;i<=n;i++){
        if (i<=cnt){
            cout << cnt << " ";
        } else {
            cout << cnt+(i-cnt) << " ";
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}