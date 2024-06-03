#include<iostream>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (char c: s) {
        mp[c]++;
    }
    int cnt = 0;
    for (int i=0;i<m;i++) {
        for (char c='A';c<='G';c++) {
            if (mp[c]==0) {
                cnt+=1;
            } else {
                mp[c]-= 1;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}