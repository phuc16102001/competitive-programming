#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = a[0];
    vector<int> pos;
    int m = n;
    for (int i=1;i<n;i++) {
        if (a[i] != x) {
            pos.push_back(i);
            m = min(m, min(i, n-i-1));
        }
    }
    if (pos.size()==0) {
        cout << "-1\n";
        return;
    }
    for (int i=0;i<pos.size()-1;i++) {
        m = min(m, pos[i+1]-pos[i]-1);
    }
    if (m==n) {
        cout << "-1\n";
        return;
    }
    cout << m << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}