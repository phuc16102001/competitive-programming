#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

void solve() {
    int n;
    cin >> n;
    vector<unsigned int> a(n, 0);
    vector<unsigned int> b(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    int idx = 0;
    for (int i=1;i<n;i++){
        if (a[idx]<a[i]) {
            idx = i;
        }
    }

    while (b[idx]!=0) {
        cout << a[idx] << " ";
        int value = b[idx];
        idx = 0;
        for (int i=0;i<n;i++) {
            b[i] = b[i] & (~value);
            if (b[i]>b[idx]) idx = i;
        }
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}