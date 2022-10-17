#include<iostream>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x>y) swap(x,y);

    if (x==0){
        if (y==0 || (n-1)%y!=0){
            cout << -1;
        } else {
            int first = 1;
            for (int i=1;i<=n;){
                for (int j=0;j<y;j++){
                    cout << i << " ";
                }
                i+=y+first;
                first = 0;
            }
        }
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}