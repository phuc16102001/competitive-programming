#include <iostream>
#include <vector>
#include <math.h>
#define ll long long
using namespace std;

ll get(ll r)
{
    ll cnt = 0;
    for (ll x = 0; x < r; x++)
    {
        ll tmp = r * r - x * x;
        ll maxY = sqrtl(tmp);
        if (maxY * maxY == tmp)
        {
            maxY -= 1;
        }

        if (x == 0)
        {
            cnt += 2 * maxY;
        }
        else
        {
            cnt += 4 * maxY + 2;
        }
    }
    return cnt;
}

void solve()
{
    ll r;
    cin >> r;
    cout << get(r + 1) - get(r) << endl;
}

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
        solve();
}