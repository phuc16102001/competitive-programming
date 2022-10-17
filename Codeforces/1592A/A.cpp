#include <iostream>
#include <vector>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve() {
    int n, h;
    vector<int> a;
    int idx1 = 0, idx2 = 0;
    cin >> n >> h;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        a.push_back(t);
        if (a[i]>a[idx1]) {
            idx1=i;
        }
    }
    if (idx2==idx1) {
        idx2++;
    }
    for (int i=idx2;i<n;i++) {
        if (i!=idx1) {
            if (a[i]>a[idx2]) {
                idx2=i;
            }
        }
    }
    int s = a[idx1]+a[idx2];
    int count = (h/s)*2;
    h = h%s;
    while (h>0) {
        h -= a[idx1];
        swap(idx1,idx2);
        count++;
    }
    cout << count << endl;
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}