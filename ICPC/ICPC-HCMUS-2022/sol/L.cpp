#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    stack<int> s;
    int cnt = 0;
    for (int x:a){
        while (s.size() && s.top()<x) {
            s.pop();
            cnt++;
        }
        if (s.size()) cnt++;
        s.push(x);
    }
    cout << cnt << endl;
}