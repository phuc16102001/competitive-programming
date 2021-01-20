#include <iostream>
using namespace std;

void solve() {
    int n;
    string s;

    cin >> n >> s;
    int pre = 1 + int(s[0]) - 48;
    cout << "1";
    for (int i = 1; i < n;i++) {
        int num = int(s[i]) - 48;
        if (num+1==pre) {
            cout << "0";
            pre = num;
        } else {
            cout << "1";
            pre = num + 1;
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}