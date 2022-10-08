#include<bits/stdc++.h>
using namespace std;

#define forf(i,a,b) for(int i=a;i<=b;i++)

int solve() {
    int b[11];
    int n, cnt = 0;

    forf(i,1,10) b[i]=-1;
    cin >> n;
    forf(i,1,n) {
        int x, y;
        cin >> x >> y;
        if (b[y]==-1) {
            cnt++;
            b[y] = x; 
        } else
        if (b[y]<x) {
            b[y] = x; 
        }
    }

    if (cnt<10) {
        cout << "MOREPROBLEM\n";
    } else {
        int s = 0;
        forf(i,1,10) s+=b[i]; 
        cout << s;
    }
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}