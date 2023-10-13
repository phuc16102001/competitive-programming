#include<iostream>
#include<set>
using namespace std;

void solve() {
    set<int> s;
    int n;
    cin >> n;
    
    int minValue = 0;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        s.insert(t);
        if (i==0 || t < minValue) {
            minValue = t;
        }
    }

    int cnt = 0;
    if (minValue == 0) {
        while (s.find(cnt) != s.end()) {
            cnt += 1;
        }
    }

    int bob = cnt+1;
    while (true) {
        if (bob == -1) {
            return;
        }
        if (bob <= cnt) {
            cout << bob << endl;
        } else {
            cout << cnt << endl;
            s.insert(cnt);
            while (s.find(cnt) != s.end()) {
                cnt += 1;
            }
        }
        cout.flush();
        cin >> bob;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}