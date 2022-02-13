#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long

ll s;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    s=0;
    bool hasGreaterOne = false;
    int nOdd = 0;
    for (int i=1;i<n-1;i++){        
        if (a[i]%2==1){
            nOdd++;
        }
        if (a[i]>1) {
            hasGreaterOne = true;
        }
        s+=a[i];
    }

    if (!hasGreaterOne || (n==3 && a[1]%2==1)){
        cout << "-1\n";
        return;
    }
    cout << ((s-nOdd)/2)+nOdd << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}