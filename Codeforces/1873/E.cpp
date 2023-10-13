#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int i = 0;
    int h = a[0];
    while (i < n - 1)
    {
        if (a[i] < a[i + 1])
        {
            int delta = a[i+1] - a[i];
            int nBlock = i+1;
            int canPush = x / nBlock;
            if (canPush < delta) {
                h += canPush;
                cout << h << endl;
                return;
            } else {
                x -= delta * nBlock;
                h += delta;
                i++;
            }
        } else {
            i++;
        }
    }
    int canPush = x / n;
    cout << h + canPush << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}