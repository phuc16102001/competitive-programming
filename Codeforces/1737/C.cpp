#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define forf(i,a,b) for (int i=a;i<=b;i++)
#define forb(i,a,b) for (int i=a;i>=b;i--)

#define NONE 0
#define DIAGONAL 1
#define HORIZONTAL 2
#define VERTICAL 3

struct Point {
    int x;
    int y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(int iX, int iY) {
        x = iX;
        y = iY;
    }
};

bool solve() {
    int n;
    int r1, r2, r3;
    int c1, c2, c3;
    int x, y;
    cin >> n;
    cin >> r1 >> c1;
    cin >> r2 >> c2;
    cin >> r3 >> c3;
    cin >> x >> y;

    Point p1 = Point(r1,c1);
    Point p2 = Point(r2,c2);
    Point p3 = Point(r3,c3);
    Point p = Point(x,y);

    // Get Point at corner of L
    int row, col;
    if (p1.x==p2.x) {
        col = p1.x;
    } else {
        col = p3.x;
    }
    if (p1.y==p2.y) {
        row = p1.y;
    } else {
        row = p3.y;
    }

    // If that point is on the corner of the board
    if ((row==1 || row==n) && (col==1 || col==n)) {
        // The target must be on the same col/row
        bool case1 = p.x==col;
        bool case2 = p.y==row;
        return case1 || case2;
    }

    int req1 = (abs(p.x-col)%2 == 1);
    int req2 = (abs(p.y-row)%2 == 1);
    return !(req1 && req2);
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}