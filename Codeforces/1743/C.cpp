#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(n, 0);
    long long cnt = 0;
    for (int i=0;i<n;i++){
        cin >> a[i];
        cnt += a[i];
    }
    int idx = -1;
    for (int i=0;i<n;i++) {
        if (s[i]=='0') {
            if (idx!=-1) cnt -= a[idx];
            idx = i;
        } else {
            if (idx!=-1 && a[idx]>a[i]) {
                idx = i;
            }
        }
    }
    if (idx!=-1) cnt -= a[idx];
    cout << cnt <<  endl;
}

int main(){
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}