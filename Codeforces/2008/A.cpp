#include<iostream>
using namespace std;

bool tryToTarget(int a, int b, int target) {
    for (int i=0;i<=a;i++) {
        for (int j=0;j<=b;j++) {
            if ((i - (a-i) + 2*j - 2*(b-j)) == 0) return true;
        }
    }
    return false;
}

bool solve() {
    int a, b;
    cin >> a >> b;
    return tryToTarget(a, b, 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << ((solve()) ? "YES\n": "NO\n");
    }
}