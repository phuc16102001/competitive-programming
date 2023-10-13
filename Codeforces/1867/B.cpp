#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int cntFlip=0, cntRemain=0;
    for (int i=0;i<n/2;i++) {
        if (s[i]!=s[n-i-1]) {
            cntFlip += 1;
        } else {
            cntRemain += 2;
        }
    }

    for (int i=0;i<=n;i++) {
        if (i<cntFlip) {
            cout << "0";
        } else if (i==cntFlip) {
            cout << "1";
        } else {
            int needFlip = i - cntFlip;
            if (needFlip % 2 != 0) {
                if (n%2==1) {
                    needFlip -= 1;
                } else {
                    cout << "0";
                    continue;
                }
            }

            if (needFlip <= cntRemain) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}