#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x[3],y[3];
    for (int i=0;i<3;i++){
        cin >> x[i] >> y[i];
    }
    int a[3] = {y[0]-y[1],y[1]-y[2],y[0]-y[2]};
    int b[3] = {x[0]-x[1],x[1]-x[2],x[0]-x[2]};
    int c[3] = {y[2]<y[1],y[0]<y[1],y[1]<y[2]};
    int s=0;
    for (int i=0;i<3;i++){
        if (a[i]==0 && c[i]) {
            s+=abs(b[i]);
        }
    }
    cout << s << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}