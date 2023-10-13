#include<iostream>
using namespace std;

void solve(){
    string a, b;
    int n, m;
    cin >> n >> m >> a >> b;
    bool result;
    int cnt = 0;
    while (a.find(b) == string::npos && a.length() <= b.length()*2) {
        a = a + a;
        cnt += 1;
    }
    if (a.find(b) != string::npos) {
        cout << cnt << endl;
    } else {
        cout << "-1\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}