#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool tryRemove(int pos, vector<int> a) {
    a.erase(a.begin() + pos);
    int n = a.size();
    vector<int> b(n-1);
    for (int i=1;i<n;i++) {
        b[i-1] = __gcd(a[i], a[i-1]);
    }
    for (int i=1;i<n-1;i++) {
        if (b[i-1]>b[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (n<=3) {
        cout << "YES\n";
        return;
    }
    
    vector<int> b(n-1);
    for (int i=1;i<n;i++) {
        b[i-1] = __gcd(a[i], a[i-1]);
    }
    // for (int x:b) cout << x << " ";
    // cout << endl;
    
    for (int i=1;i<n-1;i++) {
        if (b[i-1] > b[i]) {
            bool x1 = tryRemove(i-1, a);
            bool x2 = tryRemove(i, a);
            bool x3 = tryRemove(i+1, a);
            // cout << "Check " << i << " " << x1 << " " << x2 << " " << x3 << endl;
            if (!x1 && !x2 && !x3) {
                cout << "NO\n";
                return;
            } else {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "YES\n";
    
    
    // for (auto x: b) cout << x << " ";
    // cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}