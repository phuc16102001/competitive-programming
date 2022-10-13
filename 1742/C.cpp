#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

void solve() {  
    int n = 8;
    vector<string> a(8, "");
    string t;
    getline(cin,t);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        int cntR = 0;
        for (int j=0;j<n;j++){
            if (a[i][j]=='R') cntR++;
        }
        if (cntR==8) {
            cout << "R\n";
            return;
        }
    }

    cout << "B\n";
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}