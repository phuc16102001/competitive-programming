#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    unordered_map<int, int> bRow, bCol;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> b[i][j];
            bRow[b[i][j]] = i;
            bCol[b[i][j]] = j;
        }
    }

    for (int i=0;i<n;i++) {
        int valueAFirst = a[i][0];
        int shouldBeRow = bRow[valueAFirst];
        for (int j=1;j<m;j++) {
            int valueCur = a[i][j];
            if (bRow[valueCur] != shouldBeRow) {
                return false;
            }
        }
    }

    for (int j=0;j<m;j++) {
        int valueAFirst = a[0][j];
        int shouldBeCol = bCol[valueAFirst];
        for (int i=1;i<n;i++) {
            int valueCur = a[i][j];
            if (bCol[valueCur] != shouldBeCol) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        cout << (solve()?"YES\n":"NO\n");
    }
}