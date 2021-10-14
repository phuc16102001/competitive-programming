#include <bits/stdc++.h>
using namespace std;

int min(int a,int b) {
    return (a>b?b:a);
}

void solve() {
    string s;
    cin >> s;
    int best = 20;
    for (int i=0;i<s.length()-1;i++){
        for (int j=i+1;j<s.length();j++) {
            int k = (s[i]-'0')*10+(s[j]-'0');
            if (k==0 || k==25 || k==50 || k == 75) {
                best = min(best,s.length()-i-2);
            }
        }
    }
    cout << best << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}