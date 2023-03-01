#include <bits/stdc++.h>

#include <iostream>
using namespace std;

vector<int> tree, a;
int n, q;

// Return depth
int update(int id, int l, int r, int idx, int val) {
    if (idx < l || r < idx) {
        return 0;
    }
    if (l == idx && r == idx) {
        tree[id] = val;
        return 0;
    }

    int mid = (l + r) / 2;
    int depth = max(
        update(id * 2, l, mid, idx, val),
        update(id * 2 + 1, mid + 1, r, idx, val));
    if (depth % 2 == 0) {
        tree[id] = tree[id * 2] | tree[id * 2 + 1];
    } else {
        tree[id] = tree[id * 2] ^ tree[id * 2 + 1];
    }
    return depth + 1;
}

// Return depth
int build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return 0;
    }

    int mid = (l + r) / 2;
    int depth = max(build(id * 2, l, mid), build(id * 2 + 1, mid + 1, r));
    if (depth % 2 == 0) {
        tree[id] = tree[id * 2] | tree[id * 2 + 1];
    } else {
        tree[id] = tree[id * 2] ^ tree[id * 2 + 1];
    }
    return depth + 1;
}

int get() {
    return tree[1];
}

int main() {
    cin >> n >> q;
    n = (1 << n);

    tree.assign(4 * n + 1, 0);
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int idx, val;
        cin >> idx >> val;
        update(1, 0, n - 1, idx - 1, val);

        // for (int i = 1; i < 4 * n; i++) {
        //     cout << tree[i] << " ";
        // }
        // cout << endl;

        cout << get() << endl;
    }
}