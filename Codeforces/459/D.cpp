#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <functional>
using namespace __gnu_pbds;
using namespace std;

#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

typedef tree<
    pii, 
    null_type, 
    less<pii>, 
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

map<ll, int> cntInTree;
int n;
vector<pii> a;
vector<int> distL, distR;
ll ret = 0;

int main() {
    cin >> n;
    a.assign(n, {0, 0});
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    sort(a.begin(), a.end());

    int cnt;
    int firstIdx;

    firstIdx = a[0].se;
    distL.assign(n, 0);
    distL[firstIdx] = 1;
    cnt = 1;
    for (int i = 1; i < n; i++) {
        int val = a[i].fi;
        int prev = a[i - 1].fi;
        int idx = a[i].se;

        if (val != prev) {
            cnt = 1;
        } else {
            cnt++;
        }
        distL[idx] = cnt;
    }

    firstIdx = a[n - 1].se;
    distR.assign(n, 0);
    distR[firstIdx] = 1;
    cnt = 1;
    for (int i = n - 2; i >= 0; i--) {
        int val = a[i].fi;
        int prev = a[i + 1].fi;
        int idx = a[i].se;

        if (val != prev) {
            cnt = 1;
        } else {
            cnt++;
        }
        distR[idx] = cnt;
    }
    // for (int i = 0; i < n; i++) cout << distL[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << distR[i] << " ";
    // cout << endl;

    ordered_set s;
    for (int i = n - 2; i >= 0; i--) {
        int val = distR[i+1];
        int must_lower = distL[i];
        
        int last = cntInTree[val];
        cntInTree[val]++;
        s.insert({val, last+1});
        
        int index = s.order_of_key({must_lower-1, n});
        // cout << index << endl;
        ret += index;
    }
    cout << ret;
}