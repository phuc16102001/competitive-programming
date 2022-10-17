#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define MOD 1000000007

ll res = 0;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n, "");
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    res = 0;
    set<int> setNum;
    vector<ll> cnt(1<<m,0);
    for (int i=n-1;i>=0;i--){
        int num = stoi(a[i], nullptr, 2);
        ll nPath = (cnt[((1<<m)-1)^num]+1)%MOD; 
        res = (res+nPath)%MOD;
        cnt[num] = (cnt[num]+nPath)%MOD;
    }

    cout << res << endl;
}   

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}