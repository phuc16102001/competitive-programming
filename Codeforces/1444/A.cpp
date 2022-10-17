/*
 * Test: Input p and q that p<=1e18, q<=1e9
 * Task: Find largest x that p%x and x!%q
 * Solution: 
 * a) Check whether p%q 
 * b) If q%k then p%k, the choosen = p/k
 * Find the largest (p/k) that q%k
 * Know that if q%k then q%(q/k)
 * Time complexity: O(sqrt(q))
 */

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long p, maxValue, tmp;
long q;

void solve() {
    cin >> p >> q;
    if (p%q!=0) {
        cout << p << endl;
        return;
    }

    vector<int> divisor;
    for (int i=1;i*i<=q;i++){
        if (q%i==0) {
            divisor.push_back(i);
            if (i*i!=q){
                divisor.push_back(q/i);
            }
        }
    }

    maxValue = 0;
    for (int i=1;i<divisor.size();i++){
        tmp = p;
        while (p%q==0){
            p/=divisor[i];
        }
        if (p>maxValue) maxValue = p;
        p=tmp;
    }

    cout << maxValue << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}