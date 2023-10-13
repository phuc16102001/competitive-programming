#include<iostream>
#include<vector>
using namespace std;

void solve() {
    string s;
    int n, k;
    cin >> n >> k >> s;

    int cntLeft = 0;
    int cntRight = 0;

    int i, cnt;
    i = 0;
    while (i<n) {
        if (s[i]=='B') {
            cntLeft += 1;
            i += k;
        } else {
            i++;
        }
    }

    i = n-1;
    while (i>=0) {
        if (s[i]=='B') {
            cntRight += 1;
            i -= k;
        } else {
            i--;
        }
    }
    cout << min(cntLeft, cntRight) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}