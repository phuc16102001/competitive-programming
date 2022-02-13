#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool c=true;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (i>0){
            if (a[i]<a[i-1]){
                c=false;
            }
        }
    }
    cout << (c?"NO":"YES") << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}