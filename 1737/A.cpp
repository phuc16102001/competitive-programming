#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define forf(i,a,b) for (int i=a;i<=b;i++)
#define forb(i,a,b) for (int i=a;i>=b;i--)

void solve() {
    int n, k;
    vi a(26,0);
    cin >> n >> k;

    string s;
    cin >> s;
    forf(i,0,s.length()-1) {
        a[s[i]-'a']++;
    }
    int t = k;
    while (t--){
        int cnt = n/k;
        int idx = 0;
        bool done = false;
        while (idx<26 && (cnt || !done)) {
            // cout << t << " "  << a[idx] << " " <<  char(idx+'a') << endl;
            if (a[idx]!=0){
                if (cnt==0) {
                    done = true;
                    cout << (char)(idx+'a');
                } else {
                    a[idx]--;
                    cnt--;
                }
            } else if (!done) {
                done = true;
                cout << (char)(idx+'a');
            }
            idx++;
        }
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}