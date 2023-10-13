#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<int> a;

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    int minDiff = -1;
    bool flag = false;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (i>0) {
            int diff = a[i]-a[i-1];
            if (diff<0) {
                flag = true;
                continue;
            }
            if ((minDiff == -1) || minDiff > diff) {
                minDiff = diff;
            }
        }
    }
    if (flag) {
        cout << "0\n";
    } else {
        cout << int(ceil((minDiff+1)*1.0/2)) << endl;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        solve();
    }
}