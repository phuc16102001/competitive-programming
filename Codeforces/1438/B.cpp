//If only 2 same number add together it will up one (001+001=010)
//But if there are 2 numbers satisfied so we can choose l1=r1 is 1st num and l2=r2 is 2nd num

#include <iostream>
#include <set>
using namespace std;

void solve(){
    int n, t;
    long a[1001];
    set<int> check;
    
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++){
        if (check.find(a[i])!=check.end()) {
            cout << "YES\n";
            return;
        }
        check.insert(a[i]);
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}