#include <iostream>
using namespace std;

int a[13];
int b[100000];
int cnt, n;

int main() {
    cin >> n;

    cnt = 0;
    a[0] = 1;
    for (int i = 1; i <= 9; i++) {
        a[i] = a[i - 1] * i;
    }

    int t = 9;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    
    while (n > 0) {
        if (n - a[t] < 0) {
            t--;
        } else {
            n -= a[t];
            b[cnt++] = t;
        }
    }
    for (int i = cnt - 1; i >= 0; i--) {
        cout << b[i];
    }
}
