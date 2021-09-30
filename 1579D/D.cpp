#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>

void solve() {
    int n;
    long long s=0;
    priority_queue<pii> a;
    vector<pii> ans;

    cin >> n;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        if (t>0) {
            a.push({t,i+1});
        }
    }
    n = a.size();

    while (a.size()>1){
        pii x1=a.top();a.pop();
        pii x2=a.top();a.pop();
        x1.first--;
        x2.first--;
        if (x1.first>0) { a.push({x1.first,x1.second}); }
        if (x2.first>0) { a.push({x2.first,x2.second}); }
        ans.push_back({x1.second,x2.second});
    }

    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}