#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

#define pb push_back
#define pii pair<int, int>
#define ll long long 
#define fi first
#define se second

void solve() {
    int n;
    string s;
    cin >> n >> s;
    unordered_map<char, int> mp;
    vector<pii> a;
    for (char c:s) mp[c]++;
    for (char c='a';c<='z';c++) {
        if (mp[c] != 0) a.pb({mp[c], c});
    }
    sort(a.begin(), a.end());
    string res = "";
    int left = 0;
    int right = a.size()-1;
    while (left<=right) {
        char cRight = a[right].se;
        char cLeft = a[left].se;
        if (mp[cRight] > 0) { res += cRight; mp[cRight]--; }
        if (mp[cLeft] > 0) { res += cLeft; mp[cLeft]--; }
        if (mp[cRight] == 0) right--;
        if (mp[cLeft] == 0) left++;
    }
    cout << res << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}