#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

void solve() {  
    int n;
    vector<int> a;
    cin >> n;
    a.assign(n,0);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    bool flag = true;
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++) {
            if (a[i]==a[j]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}