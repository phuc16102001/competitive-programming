#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define forf(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define max(a,b) (a>b?a:b)
#define pb push_back

vi parent;
vector<vi> child;
int cntNode, minHeight;

int findHeight(int node) {
    int h = 1;
    for (auto next:child[node]) {
        int nextHeight = findHeight(next);
        h = max(h, nextHeight+1);
    }
    if (h==minHeight && parent[node]!=-1 && parent[node]!=1) {
        cntNode++;
        return 0;
    }
    return h;
}

void solve() {
    int n, k;
    cin >> n >> k;

    parent.assign(n+1, -1);
    child.assign(n+1, {});

    forf(i,2,n) {
        int t;
        cin >> t;
        child[t].pb(i);
        parent[i] = t;
    }

    // Finding minHeight that can achieve with maximum K splash
    int l=1;
    int r=n-1;
    int res = n-1;
    while (l<=r) {
        int mid = (l+r)/2;
        cntNode = 0;
        minHeight = mid;
        findHeight(1);

        if (cntNode<=k) {
            res = minHeight;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << res << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}