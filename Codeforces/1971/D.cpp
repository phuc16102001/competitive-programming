#include <iostream>
using namespace std;

int solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int cntChange = 1;
    int exist01 = false;
    for (int i=1;i<n;i++) {
        cntChange += (s[i] != s[i-1]);
        if (s[i-1]=='0' && s[i]=='1') exist01 = true;
    }
    return cntChange - exist01;
}

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
        cout << solve() << endl;
}