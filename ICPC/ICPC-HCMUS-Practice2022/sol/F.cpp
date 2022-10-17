#include<bits/stdc++.h>
using namespace std;

#define forf(i,a,b) for(int i=a;i<=b;i++)
#define max(a,b) (a>b)?a:b

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> r(n), w(n);
    int maxR=0, maxW=0;
    forf(i,0,m-1) {
        cin >> r[i] >> w[i];
        maxR = max(r[i], maxR);
        maxW = max(w[i], maxW);
    }
    if (maxR+maxW>n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    forf(i,1,maxR) cout << "R";
    forf(i,1,maxW) cout << "W";
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}