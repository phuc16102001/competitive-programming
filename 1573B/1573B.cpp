#include <bits/stdc++.h>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>

void heapify(vector<pii>& a, int n, int root) {
    int largest = root;
    int c1 = root*2+1;
    int c2 = root*2+2;

    if (c1<n && a[c1]>a[largest]) {
        largest = c1;
    }
    if (c2<n && a[c2]>a[largest]) {
        largest = c2;
    }
    // cout << largest << " "<< root << endl;
    if (largest!=root) {
        swap(a[largest],a[root]);
        heapify(a,n,largest);
    }
}

void heapSort(vector<pii>& a, int n) {
    for (int i=n/2-1;i>=0;i--) {
        heapify(a,n,i);
    }
    for (int i=n-1;i>0;i--) {
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}

void debug(vector<int> a, vector<pii> b, int n) {
// void debug(){
    cout << "== DEBUG == \n";
    for (int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i=0;i<n;i++) {
        cout << b[i].first << " ";
    }
    cout << endl;
    for (int i=0;i<n;i++) {
        cout << b[i].second << " ";
    }
    cout << endl;
    // cout << endl;
    // srand(time(NULL));
    // vector<pii> k;
    // int n=10;
    // for (int i=0;i<n;i++){
    //     k.push_back(rand());
    // }
    // for (int i=0;i<n;i++) {
    //     cout << k[i] << " ";
    // }
    // cout << endl;
    // heapSort(k,n);
}

void solve(){
    int n;
    cin >> n;

    vector<int> a;
    vector<pii> b;

    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        b.push_back(pii(t,i));
    }

    heapSort(b,n);
    for (int i=n-2;i>=0;i--) {
        b[i].second = min(b[i].second,b[i+1].second); 
    }
    // debug(a,b,n);

    int s = n;
    for (int i=0;i<n;i++) {
        int idx = (a[i]-1)/2;
        int val = i+(b[idx].second);
        s = min(s,val);
    }
    cout << s << endl;
}

int main() {
    fast;
    int nTest;
    cin >> nTest;
    while(nTest--) {
        solve();
    }
    // debug();
}