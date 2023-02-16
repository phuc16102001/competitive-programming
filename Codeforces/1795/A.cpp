#include<iostream>
using namespace std;

void solve() {
    int n1, n2;
    string a, b;
    cin >> n1 >> n2 >> a >> b;

    for (int i=b.length()-1;i>=0;i--) {
        a += b[i];
    }
    int cnt = 0;
    for (int i=0;i<a.length();i++) {
        if (a[i]==a[i+1]) {
            cnt++;
        }
    }
    if (cnt<2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}