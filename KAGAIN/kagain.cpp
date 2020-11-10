#include <iostream>
#include <stack>
using namespace std;

void solve() {
    int n,a[30001];
    cin >> n;
    for (int i=0;i<n;cin>>a[i++]);

    int l[30001],r[30001];
    stack<int> d;
    d.push(-1);
    for (int i=0;i<n;i++){
        while (d.size()>1 && a[d.top()]>=a[i]) {
            d.pop();
        }
        l[i]=d.top()+1;
        d.push(i);
    }

    while (!d.empty()) {
        d.pop();
    }
    d.push(n);
    for (int i=n-1;i>=0;i--){
        while (d.size()>1 && a[d.top()]>=a[i]) {
            d.pop();
        }
        r[i]=d.top()-1;
        d.push(i);
    }

    int result = 0;
    int vr = (r[result]-l[result]+1)*a[result];
    for (int i=1;i<n;i++){
        int vi = (r[i]-l[i]+1)*a[i];
        if (vi>vr) {
            result = i;
            vr = vi;
        }
    }

    cout << vr << " " << l[result]+1 << " " << r[result]+1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}   