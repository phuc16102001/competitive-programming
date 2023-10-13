#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    vector<string> a(10, "");
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    int score = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] == 'X')
            {
                int mi = i > 4 ? 9 - i : i;
                int mj = j > 4 ? 9 - j : j;
                for (int k = 0; k <= 4; k++)
                {
                    if (mi == k || mj == k)
                    {
                        score += k + 1;
                        break;
                    }
                }
            }
        }
    }
    cout << score << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}