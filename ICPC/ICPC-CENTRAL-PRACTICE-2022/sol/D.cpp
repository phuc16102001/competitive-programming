#include <bits/stdc++.h>
using namespace std;

#define NORMAL 0
#define ROTATE 1

struct Point {
    int x, y;
    Point() : x(0), y(0){};
    Point(int ix, int iy) : x(ix), y(iy){};
};

struct Rectangle {
    int x, y, w, h;
    Rectangle() : x(0), y(0), w(0), h(0){};
    Rectangle(int ix, int iy, int iw, int ih) : x(ix), y(iy), w(iw), h(ih){};

    Rectangle rotate() {
        Rectangle result(x, y, h, w);
        return result;
    }

    Point getLeftTop() {
        Point result(x - w / 2, y + h / 2);
        return result;
    }

    Point getBottomRight() {
        Point result(x + w / 2, y - h / 2);
        return result;
    }
};

bool isOverlap(Rectangle& rectA, Rectangle& rectB) {
    Point leftTopA = rectA.getLeftTop();
    Point leftTopB = rectB.getLeftTop();
    Point rightBottomA = rectA.getBottomRight();
    Point rightBottomB = rectB.getBottomRight();

    if (leftTopA.x >= rightBottomB.x || leftTopB.x >= rightBottomA.x) {
        return false;
    }

    if (leftTopA.y <= rightBottomB.y || leftTopB.y <= rightBottomA.y) {
        return false;
    }
    return true;
}

int n;
vector<vector<bool>> checkType;
vector<Rectangle> a;

int main() {
    cin >> n;
    checkType.assign(2, vector<bool>(n, true));
    a.assign(n, Rectangle());
    for (int i = 0; i < n; i++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        a[i] = Rectangle(x, y, w, h);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            Rectangle rectA = a[i];
            Rectangle rectB = a[j];
            Rectangle rotateA = rectA.rotate();
            Rectangle rotateB = rectB.rotate();
            bool c1 = isOverlap(rectA, rectB) && isOverlap(rectA, rotateB);
            bool c2 = isOverlap(rectA, rectB) && isOverlap(rotateA, rectB);
            bool c3 = isOverlap(rotateA, rectB) && isOverlap(rotateA, rotateB);
            bool c4 = isOverlap(rectA, rotateB) && isOverlap(rotateA, rotateB);
            if (c1) checkType[NORMAL][i] = false;
            if (c2) checkType[NORMAL][j] = false;
            if (c3) checkType[ROTATE][i] = false;
            if (c4) checkType[ROTATE][j] = false;

            bool f1 = checkType[NORMAL][i] == false && checkType[ROTATE][i] == false;
            bool f2 = checkType[NORMAL][j] == false && checkType[ROTATE][j] == false;
            if (f1 || f2) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = NORMAL; j <= ROTATE; j++) {
            if (checkType[j][i]) {
                cout << (j ? "Q" : "K");
                break;
            }
        }
    }
    return 0;
}