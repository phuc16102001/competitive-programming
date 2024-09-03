#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>
using namespace std;

int calcState(int n, unordered_map<char, int>& odd, unordered_map<char, int>& even) {
    int cntOdd = n/2 + (n%2);
    int cntEven = n/2;
    int minMoveOdd = INT_MAX;
    int minMoveEven = INT_MAX;
    for (char c='a';c<='z';c++) {
        minMoveOdd = min(minMoveOdd, cntOdd - odd[c]);
        minMoveEven = min(minMoveEven, cntEven - even[c]);
    }
    return minMoveOdd + minMoveEven;
}

void debug(unordered_map<char, int>& odd, unordered_map<char, int>& even) {
    cout << "==== START DEBUG ====\n";
    cout << "ODD:\n";
    for (char c='a';c<='z';c++) {
        cout << c << " " << odd[c] << " ";
    }
    cout << endl;
    cout << "EVEN:\n";
    for (char c='a';c<='z';c++) {
        cout << c << " " << even[c] << " ";
    }
    cout << endl;
    cout << "==== END DEBUG ====\n";
}

int solve() {
    int n;
    string s;
    cin >> n >> s;
    //cout << "SOLVE(" << s << ")\n";

    unordered_map<char, int> allOdd, allEven, prevOdd, prevEven;
    for (int i=0;i<n;i++) {
        char c=s[i];
        if (i%2) allOdd[c]++;
        else allEven[c]++;
    }
    //debug(allOdd, allEven);
    if (n%2==0) return calcState(n, allOdd, allEven);
    int res = INT_MAX;
    
    for (int i=n-1;i>=0;i--) {
        if (i%2) allOdd[s[i]]--;
        else allEven[s[i]]--;

        for (char c='a';c<='z';c++) {
            allOdd[c] -= prevOdd[c];
            allOdd[c] += prevEven[c];
            allEven[c] -= prevEven[c];
            allEven[c] += prevOdd[c];
        }
        int newRes = calcState(n, allOdd, allEven);
        res = min(res, newRes);
        for (char c='a';c<='z';c++) {
            allOdd[c] += prevOdd[c];
            allOdd[c] -= prevEven[c];
            allEven[c] += prevEven[c];
            allEven[c] -= prevOdd[c];
        }

        if (i%2) allOdd[s[i]]++;
        else allEven[s[i]]++;
        
        if (i%2) prevOdd[s[i]]++;
        else prevEven[s[i]]++;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
}