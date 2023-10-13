#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0), h(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int left, right, res;
    left = 0;
    right = 0;
    res = 0;
    while (left < n)
    {
        right = left;
        while (right < n - 1 && h[right] % h[right + 1] == 0)
        {
            right++;
        }

        int i, j;
        i = left;
        j = left;
        int s = 0;
        int cnt = 0;
        while (i<=right && j <= right) {
            if (s + a[j] <= k) {
                s += a[j];
                cnt += 1;
                j++;
            } else {
                s -= a[i];
                cnt -= 1;
                i++;
            }
            if (cnt > res) {
                res = cnt;
            }
        }

        // Update left
        left = right + 1;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}