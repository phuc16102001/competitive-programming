#include <iostream>
using namespace std;

bool solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b)
    {
        swap(a, b);
    }
    if (c > d)
    {
        swap(c, d);
    }
    if (a < c && c < b)
    {
        return !(a < d && d < b);
    }
    if (a < d && d < b)
    {
        return !(a < c && c < b);
    }
    return false;
}

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
        cout << ((solve()) ? "YES\n" : "NO\n");
}