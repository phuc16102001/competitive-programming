#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define forf(i,a,b) for(int i=a;i<=b;i++)

void solve() {
    int n;
    cin >> n;
    cout << (n-3)/3-1 << "\n";
}

int main() {
    int nTest;
    cin >> nTest;
    forf(i,1,nTest) solve();
}