#include <iostream>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0]) {
        cout << "YES\n"
             << a[0] << "*\n";
        return;
    }
    if (a[a.length() - 1] == b[b.length() - 1]) {
        cout << "YES\n"
             << "*" << a[a.length() - 1] << "\n";
        return;
    }
    for (int i = 0; i < a.length() - 1; i++) {
        for (int j = 0; j < b.length() -1; j++) {
            if (a.substr(i, 2) == b.substr(j, 2)) {
                cout << "YES\n*" << a.substr(i, 2) << "*\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}