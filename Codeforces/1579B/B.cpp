#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);

struct Move {
    int l, r, d;
    Move(int _l, int _r, int _d):l(_l),r(_r),d(_d){};
};

void solve() {
    int n,a[50];
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    vector<Move> ret;
    for (int i=n-2;i>=0;i--) {
        int k = i;
        while (k+1<n && a[k]>a[k+1]) {
            swap(a[k],a[k+1]);
            k++;
        }
        if (k!=i) {
            ret.push_back(Move(i,k,1));
        }
    }
    cout << ret.size() << endl;
    for (Move m:ret) {
        cout << m.l+1 << " " << m.r+1 << " " << m.d << endl;
    }
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}