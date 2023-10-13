#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;

int convertToSpace(int k, int n) {
    if (k < n/2) {
        return k-n/2;
    } else {
        return (k-(n/2-1));
    }
}

int convertFromSpace(int k, int n) {
    if (k<0) {
        return k+n/2;
    } else {
        return (k+(n/2-1));
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n, "");
    vector< vector<bool> > check(n, vector<bool>(n, false));
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    
    int cnt = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (!check[i][j]) {
                vector<int> ls;
                ls.pb(a[i][j]);
                check[i][j] = true;
                int x, y;
                x = convertToSpace(j,n);
                y = convertToSpace(i,n);
                for (int i=0;i<3;i++) {
                    int t = y;
                    y = -x;
                    x = t;
                    int nj = convertFromSpace(x, n);
                    int ni = convertFromSpace(y, n);
                    ls.pb(a[ni][nj]);
                    check[ni][nj] = true;
                }
                sort(ls.begin(), ls.end());
                for (int i=0;i<3;i++) {
                    cnt += ls[3]-ls[i];
                }
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}