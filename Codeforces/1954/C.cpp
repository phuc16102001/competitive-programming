#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void solve() {
    string s1, s2;
    string t1, t2;
    cin >> s1 >> s2;
    t1 = s1[0];
    t2 = s2[0];
    int n = s1.length();
    for (int i=1;i<n;i++) {
        int v = 0;
        if (s2[i] > s1[i]) {
            v = 1;
        }
        // cout << t1 << " " << t2 << " " << s2[i] << " " << s1[i] << endl;
        bool c1 = (t1 < t2 && v == 1);
        bool c2 = (t1 > t2 && v == 0);
        // cout << i << " " << c1 << " " << c2 << endl;
        if (c1 || c2) {
            char x = s1[i];
            s1[i] = s2[i];
            s2[i] = x;
        } 
        t1 += s1[i];
        t2 += s2[i];
    }
    cout << s1 << "\n" << s2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}