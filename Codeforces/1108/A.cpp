#include <iostream>
using namespace std;

struct seg {
    int l, r;
};

void solve(){
    seg s1,s2;
    cin >> s1.l >> s1.r >> s2.l >> s2.r;

    int a = s1.l;
    int b = s2.l;
    if (a==b) {     //s1.l=s2.l
        b=s2.r;
        if (a==b){  //s2.l=s2.r=s1.l
            a=s1.r;
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}