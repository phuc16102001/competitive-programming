#include<iostream>
#include<vector>
#include<algorithm>
#define MODULO 1000000007
#define ll long long
using namespace std;


ll solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i=0;i<n;i++) cin >> a[i];
    if (n==1) return k - 1 + (a[0]<k);

    int cur = a[0];
    for (int i=1;i<n;i++) {
        cur = __gcd(cur, a[i]);
    }

    if (cur == 1) return k + n -1;
    
    int tmp = 0;
    while (n) {
        if (tmp >= k) break;
        k++;
        tmp += cur;
        n--;
    }
    return k-1;
}

int main() {
    int n;
    cin >> n;
    while (n--) cout << solve() << endl;
}