#include <iostream>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int count = 0;
    for (int i = 0; i < n;i++){
        if (a[i]<b[i]) {
            count++;
        } else
        if (a[i]>b[i]) {
            count--;
        }
    }
    if (count>0) {
        cout << "BLUE\n";
    } else 
    if (count<0) {
        cout << "RED\n";
    } else {
        cout << "EQUAL\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}