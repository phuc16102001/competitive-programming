#include <iostream>
using namespace std;

long long ceil(long long a, long long b) {
    if (a%b==0) {
        return a / b;
    }
    return (a / b + 1);
}

void solve() {
    long long n, x, sum2, sum1;
    sum2 = sum1 = 0;

    cin >> n >> x;
    for (int i = 0; i < n;i++){
        int tmp;
        cin >> tmp;
        sum1 += tmp;
        sum2 += ceil(tmp,x);
    }
    sum1 = ceil(sum1,x);
    cout << sum1 << " " << sum2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}