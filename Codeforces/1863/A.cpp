#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;

    int cntPlus = 0;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='+') cntPlus += 1;
    }
    int cntMinus = s.length() - cntPlus;

    bool bestCase = (a+cntPlus >= n);
    bool worstCase = true;
    for (int i=0;i<s.length();i++) {
        if (a>=n) {
            worstCase = false;
        }
        a += (s[i]=='+') ? 1 : -1;
    }
    if (a>=n) {
        worstCase = false;
    }
    if (bestCase && !worstCase) {
        cout << "YES\n";
        return;
    }
    if (!bestCase) {
        cout << "NO\n";
        return;
    }
    cout << "MAYBE\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}