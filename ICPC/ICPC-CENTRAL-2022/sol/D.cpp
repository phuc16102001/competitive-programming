#include <bits/stdc++.h>

using namespace std;

int a[100005];

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex* l, Vertex* r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm + 1, tr));
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum + 1);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos));
}

int find_kth(Vertex* vl, Vertex* vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = (tl + tr) / 2, left_count = vr->l->sum - vl->l->sum;
    if (left_count >= k)
        return find_kth(vl->l, vr->l, tl, tm, k);
    return find_kth(vl->r, vr->r, tm + 1, tr, k - left_count);
}

signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    int tl = 0, tr = 100005;
    vector<Vertex*> roots;
    roots.push_back(build(tl, tr));
    for (int i = 0; i < n; i++)
        roots.push_back(update(roots.back(), tl, tr, a[i]));

    while (q--) {
        int l, r;
        cin >> l >> r;
        int result = find_kth(roots[l - 1], roots[r], tl, tr, (r - l) / 2 + 1);
        cout << result << "\n";
    }
    return 0;
}