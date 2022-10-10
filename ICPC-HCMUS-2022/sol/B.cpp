#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, wFull, area=0;
    cin >> wFull >> n;
    while (n--) {
        int w, l;
        cin >> w >> l;
        area += w*l;
    }
    cout << area/wFull;
}