#include<iostream>
using namespace std;

int solve() {
    int l, r;
    cin >> l >> r;
    int cur = 1;
    int len = 1;
    while (l<=r) {
        l += cur;
        cur++;
        len++;
    }
    return len-1;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}