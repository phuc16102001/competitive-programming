#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define vi vector<int, int>

#define QUYEN 1
#define THANG 0

int n, k;
string s;
int dp[301][301][301] = {0};
int prefixB[300] = {0};

bool test(int left, int right, int qLeft) {
    if (left>=right) return QUYEN;

    int nBPicked = prefixB[n - 1] - (prefixB[right] - prefixB[left] + (s[left] == 'B'));
    int tPicked = nBPicked - (k - qLeft);
    int tLeft = k - tPicked;
    if (qLeft == 0) {
        return THANG;
    } else if (tLeft == 0) {
        return QUYEN;
    }

    if (qLeft >= 0 && dp[left][right][qLeft]) return dp[left][right][qLeft] - 1;

    bool player = ((n - (right - left + 1)) % 2 == 0);
    bool result;

    char leftChar = s[left];
    char rightChar = s[right];

    bool c1 = test(
        left + 1,
        right,
        (player == QUYEN && leftChar == 'B') ? qLeft - 1 : qLeft);
    bool c2 = test(
        left,
        right - 1,
        (player == QUYEN && rightChar == 'B') ? qLeft - 1 : qLeft);
    if (player == THANG) {
        result = 1 - ((1 - c1) || (1 - c2));
    } else {
        result = c1 || c2;
    }
    dp[left][right][qLeft] = result + 1;
    return result;
}

void preprocess() {
    prefixB[0] = (s[0] == 'B');
    for (int i = 1; i < s.length(); i++) {
        prefixB[i] = prefixB[i - 1] + (s[i] == 'B');
    }
}

int main() {
    cin >> n >> k >> s;
    preprocess();
    if (test(0, n - 1, k)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}