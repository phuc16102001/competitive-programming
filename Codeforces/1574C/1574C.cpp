#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll unsigned long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

const int MAXN = 2e5;
const ll INF = LLONG_MAX;

int n ,m;
ll x, y, a[MAXN];
ll s = 0;

ll min(ll a, ll b, ll c){
    return min(min(a,b),c);
}

void heapify(ll* a, int root, int n) {
    int c1 = root*2+1;
    int c2 = root*2+2;
    int largest = root;
    if (c1<n && a[c1]>a[largest]) {
        largest = c1;
    }
    if (c2<n && a[c2]>a[largest]) {
        largest = c2;
    }
    if (largest!=root) {
        swap(a[largest],a[root]);
        heapify(a,largest,n);
    }
}

void heapSort(ll* a, int n) {
    for (int i=n/2;i>=0;i--) {
        heapify(a,i,n);
    }
    for (int i=n-1;i>0;i--) {
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

int binarySearch(ll* a, ll x, int l, int r) {
    if (r<=l) {
        while (l-1>=0 && a[l-1]>=x) {
            l--;
        }
        return l;
    }
    int mid = (l+r)/2;
    if (a[mid]==x) {
        return mid;
    } else
    if (a[mid]<x) {
        return binarySearch(a,x,mid+1,r);
    } else {
        return binarySearch(a,x,l,mid-1);
    }
}

ll test(ll* a, ll x, ll y, ll s, int idx) {  
    if (idx<0||idx>=n) {
        return INF;
    }
    s -= a[idx];
    ll coin = 0;
    if (a[idx]<x) {
        coin += x-a[idx];
    }
    if (s<y) {
        coin += y-s;
    }
    return coin;
}

// #include <stdio.h>      /* printf, scanf, puts, NULL */
// #include <stdlib.h>     /* srand, rand */
// #include <time.h>       /* time */
// void debug() {
//     srand(time(NULL));
//     n = 100;
//     for (int i=0;i<n;i++) {
//         a[i] = rand();
//     }
//     heapSort(a,n);
//     for (int i=0;i<n;i++) {
//         cout << a[i] << " ";
//     }
// }

int main() {
    fast;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
        s+=a[i];
    }
    heapSort(a,n);
    // for (int i=0;i<n;i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        int idx = binarySearch(a,x,0,n-1);
        ll resA = test(a,x,y,s,idx);
        ll resB = test(a,x,y,s,idx-1);
        ll resC = test(a,x,y,s,idx+1);
        cout << min(resA,resB,resC) << endl;
    }

    // debug();
}
