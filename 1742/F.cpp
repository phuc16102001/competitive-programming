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
    
    vector<ll> a(26, 0);
    vector<ll> b(26, 0);
    vector<ll> ta(26, 0);
    vector<ll> tb(26, 0);
    a[0] = 1;
    b[0] = 1;
    for (int i=0;i<n;i++) {
        int t, k;
        string s;
        cin >> t >> k >> s;

        for (int j=0;j<s.length();j++) {
            if (t==1) {
                a[s[j]-'a']+=k;
            } else {
                b[s[j]-'a']+=k;
            }
        }

        for (int i=0;i<26;i++) {
            ta[i] = a[i];
            tb[i] = b[i];
        }

        int ida = 0;
        int idb = 25;
        while (ida<26 || idb>=0) {
            while (ida<26 && a[ida]==0) ida++;
            while (idb>=0 && b[idb]==0) idb--;
            if (idb==-1) { cout << "NO\n"; break; }
            if (ida==26) { cout <<  "YES\n"; break; }
            if (ida>idb) { cout << "NO\n"; break; }
            if (ida<idb) { cout << "YES\n"; break; }
            int cnt = min(a[ida], b[idb]);
            a[ida] -= cnt;
            b[idb] -= cnt;
        }

        for (int i=0;i<26;i++) {
            a[i] = ta[i];
            b[i] = tb[i];
        }
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}