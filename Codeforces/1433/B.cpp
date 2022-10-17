#include <iostream>
#include <deque>
#define pb push_back
#define pf push_front
using namespace std;

void solve() {
    int n, a[100];
    cin >> n;
    for (int i=0;i<n;cin>>a[i++]);
    
    deque<int> v;
    for (int i=0;i<n;i++){
        if (a[i]==0 || (a[i]==1 && (i==n-1 ||a[i+1]==0))) {
            v.pb(a[i]);
        }
    }
    int count = 0;
    while (!v.empty() && v.front()==0) v.pop_front();
    while (!v.empty() && v.back()==0) v.pop_back();
    for (int i=0;i<v.size();i++){
        if (v[i]==0) count++;
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}