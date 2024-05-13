#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <algorithm>
#include <set>
#define pii pair<int, int>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, vector< int > > mp;
    unordered_map<int, vector< int > > idx;
    set<int> distinctGroup;
    for (int i=0;i<n;i++ ){
        int group = (a[i] & ~3);
        mp[group].push_back(a[i]);
        idx[group].push_back(i);
        distinctGroup.insert(group);
    }
    vector<int> res(n, 0);
    for (int group: distinctGroup) {
        sort(mp[group].begin(), mp[group].end());
        // cout << group << ": ";
        for (int i=0;i<mp[group].size(); i++) {
            // cout << mp[group][i] << " ";
            res[idx[group][i]] = mp[group][i];
        }
        // cout << endl;
    }
    for (int x: res) cout << x << " ";    
    cout << endl;
}

int main()
{
    int nTest;
    cin >> nTest;
    while (nTest--)
        solve();
}