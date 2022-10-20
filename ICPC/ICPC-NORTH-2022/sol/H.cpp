#include <bits/stdc++.h>
#include <bits/stdtr1c++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long

typedef tree<
    ll,
    null_type,
    less_equal<ll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    RBTree;

RBTree a;

void solve() {
    string op;
    ll x;
    cin >> op;
    if (op == "IN") {
        cin >> x;
        a.insert(x);
    } else if (op == "OUT") {
        cin >> x;
        int rank = a.order_of_key(x);
        auto it = a.find_by_order(rank);
        a.erase(it);
    } else {
        int sz = a.size();
        if (sz % 2 == 1) {
            cout << *a.find_by_order(sz / 2) << "\n";
        } else {
            double cur = *a.find_by_order(sz / 2 - 1) + *a.find_by_order(sz / 2);
            cout << setprecision(1) << fixed << cur / 2.0 << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}
