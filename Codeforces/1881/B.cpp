#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    vector<int> a(3, 0);
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    int cnt = 3;
    do
    {
        sort(a.begin(), a.end());
        if (a[0]==a[2]) {
            cout << "YES\n";
            return;
        }
        a[2] -= a[0];
        cnt--;
    } while (cnt > 0);
    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}