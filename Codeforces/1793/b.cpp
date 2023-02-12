#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int a, b;
    int cnt = 0;
    cin >> a >> b;
    vector<int> x;
    for (int i=a;i>=b;i--) {
        x.push_back(i);        
    }
    for (int i=b+1;i<a;i++) {
        x.push_back(i);
    }
    cout << x.size() << endl;
    for (int i=0;i<x.size();i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        solve();
    }
}