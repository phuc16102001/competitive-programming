#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k+1, 0);
    vector<int> b(k+1, 0);
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    // for (int x : a) cout << x << " ";
    // cout << endl;
    while (q--)
    {
        int d;
        cin >> d;
        if (d == 0)
        {
            cout << "0 ";
            continue;
        }
        if (d==n) {
            cout << b[k] << " ";
            continue;
        }

        int idx = lower_bound(a.begin(), a.end(), d) - a.begin();
        if (a[idx] > d) {
            idx--;
        }
        // cout << "idx: " << idx << endl;
        // cout << "comp1: " << d-a[idx] << endl;
        // cout << "comp2: " << b[idx+1] - b[idx] << endl;
        // cout << "comp3: " << (a[idx+1] - a[idx]) << endl;
        int res = b[idx] + ((long long)(d - a[idx])) * ((long long)(b[idx+1] - b[idx])) / (a[idx+1] - a[idx]);
        cout << res << " ";
    }
    cout << endl;
}

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
        solve();
}