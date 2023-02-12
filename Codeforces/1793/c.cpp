#include <iostream>
#include <vector>
using namespace std;

#define INF 1<<15

struct Node {
    int m1;
    int m2;
};

vector<int> a;
vector<Node> st;

void build(int id, int l, int r) {
    if (l==r) {
        st[id].m1 = a[l];
        st[id].m2 = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].m1 = min(st[id*2].m1, st[id*2+1].m1);
    st[id].m2 = max(st[id*2].m2, st[id*2+1].m2);
}

int getMin(int id, int l, int r, int u, int v) {
    if (v<l || r<u) {
        return INF;
    }
    if (u<=l && r<=v) {
        return st[id].m1; 
    }
    int mid = (l+r)/2;
    return min(
        getMin(id*2, l, mid, u, v),
        getMin(id*2+1, mid+1, r, u, v)
    );
}

int getMax(int id, int l, int r, int u, int v) {
    if (v<l || r<u) {
        return -INF;
    }
    if (u<=l && r<=v) {
        return st[id].m2; 
    }
    int mid = (l+r)/2;
    return max(
        getMax(id*2, l, mid, u, v),
        getMax(id*2+1, mid+1, r, u, v)
    );
}

void solve() {
    int n;
    cin >> n;

    a.assign(n, 0);
    st.assign(n*4, Node());
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    if (n<4) {
        cout << -1 << endl;
        return;
    }

    build(1, 0, n-1);
    int p1=0, p2=n-1;
    while (p1<p2) {
        int m1 = getMin(1, 0, n-1, p1, p2);
        int m2 = getMax(1, 0, n-1, p1, p2);
        if (a[p1]==m1 || a[p1]==m2) {
            p1++;
            continue;
        }
        if (a[p2]==m1 || a[p2]==m2) {
            p2--;
            continue;
        }
        break;
    }
    if (p2-p1+1>=4) {
        cout << p1+1 << " " << p2+1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}