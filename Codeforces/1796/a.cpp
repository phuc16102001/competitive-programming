#include<iostream>
using namespace std;
    
void solve() {
    string s = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
    string a;
    int n;
    cin >> n;
    cin >> a;
    if (s.find(a)!=string::npos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}