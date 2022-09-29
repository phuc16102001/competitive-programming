#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define for(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second


int findHeight(int node, vi& p, vpii& h) {
    if (node==1) return 1;
    if (h[p[node]].se == -1) {
        h[p[node]].se = findHeight(p[node], p, h)+1;
    }
    return h[p[node]].se+1;
}

bool sortSec(pii &a , pii &b) {
    return a.se > b.se;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi p(n+1,-1);
    vpii h(n+1);
    h[1] = {1,0};
    for(i,2,n) {
        cin >> p[i];
        h[i] = {i,-1};
    }
    for(i,1,n) {
        if (h[i].se==-1) {
            h[i].se = findHeight(i, p, h);
        }
    }
    sort(h.begin()+1,h.end(),sortSec);
    for (i,1,n) {
        cout << h[i].fi << " " << h[i].se << endl;
    }
    cout << h[min(k+1,n)].se << endl<< endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}