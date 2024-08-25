#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back
#define ll long long 
#define fi first
#define se second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[n/2] << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}