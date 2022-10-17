#include<bits/stdc++.h>
using namespace std;

#define pb push_back

set<int> s;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

void findCommonDivisor(int a, int b){
    int n = gcd(a,b);
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0) {
            s.insert(i);
            if (n/i != i) {
                s.insert(n/i);
            }
        }
    }
}

void solve() {
    int w, l;
    cin >> w >> l;
    s.clear();

    findCommonDivisor(w-1, l-1);
    findCommonDivisor(w, l-2);
    findCommonDivisor(w-2, l);

    cout << s.size() << " ";
    for (auto it=s.begin();it!=s.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while(nTest--) solve();
}