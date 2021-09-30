#include <bits/stdc++.h>
#include <deque>
using namespace std;

void solve() {
    int n;
    deque<int> a;
    cin >> n;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        if (a.empty() || t<=a.front()) {
            a.push_front(t);
        } else {
            a.push_back(t);
        }
    }
    while (!a.empty()) {
        cout << a.front() << " ";
        a.pop_front();
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) solve();
}