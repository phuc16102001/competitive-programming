#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

ll res = 0;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n, "");
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    res = 0;
    vector<int> cnt(n,0);
    for (int i=n-1;i>=0;i--){
        int num = stoi(a[i], nullptr, 2);
        int nPath = cnt[((1<<m)-1)^num]+1; 
        res += nPath;
        cnt[num] += nPath;
    }
    cout << res;
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}