#include<iostream>
#include<math.h>
using namespace std;

bool solve() {
    int n;
    string s;
    cin >> n >> s;
    int sqrtN = sqrt(n);
    if (sqrtN * sqrtN != n) return false;
    for (int i=0;i<n;i++) {
        if (i%sqrtN == 0 || i%sqrtN == (sqrtN-1)) {
            if (s[i] != '1') return false;
        } else if (i/sqrtN == 0 || i/sqrtN == sqrtN-1) {
            if (s[i] != '1') return false;
        } else {
            if (s[i] != '0') return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << ((solve()) ? "YES\n": "NO\n");
    }
}