#include <bits/stdc++.h>
using namespace std;

#define e 0.0001
#define PI 3.1415926
#define sqr(x) x* x

struct Point {
    double x;
    double y;
    Point() {
        x = 0;
        y = 0;
    }
    Point(double iX, double iY) {
        x = iX;
        y = iY;
    }
};

struct Line {
    double a, b, c;
    Line() {
        a = b = c = 0;
    };
    Line(Point pA, Point pB) {
        a = pA.y - pB.y;
        b = pB.x - pA.x;
        c = pA.x * pB.y - pA.y * pB.x;
    };
};

int getIntersect(Line line1, Line line2, double& x, double& y) {
    double D, Dx, Dy;
    D = line1.a * line2.b - line1.b * line2.a;
    Dx = line1.b * line2.c - line1.c * line2.b;
    Dy = line1.c * line2.a - line1.a * line2.c;
    if (abs(D) < e) {
        if (abs(Dx) < e && abs(Dy) < e) {
            // Coincided
            return 2;
        }
        // Parallel
        return 1;
    }
    // Intersect
    x = Dx / D;
    y = Dy / D;
    return 0;
}

double distance(Point pA, Point pB) {
    double dx = pA.x - pB.x;
    double dy = pA.y - pB.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    double ax, ay;
    double bx, by;
    double cx, cy;
    double hx, hy;
    double r;
    int p;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;
    cin >> r >> p;

    Point A(ax, ay);
    Point B(bx, by);
    Point C(cx, cy);
    Line AB(A, B);
    Line CH;
    CH.a = -AB.b;
    CH.b = AB.a;
    CH.c = -(CH.a * C.x + CH.b * C.y);

    getIntersect(AB, CH, hx, hy);
    Point H(hx, hy);
    double dCH = distance(C, H);
    if (dCH >= r) {
        cout << "NO";
        return 0;
    }
    double dAH = sqrt(r * r - dCH * dCH);
    double triangleS = dCH * dAH;
    double cosC = 1 - 2 * sqr(dAH / r);
    double angC = acos(cosC);
    double cirS = PI * r * r;
    double curveS = 0.5 * angC * r * r;
    double moonS = curveS - triangleS;
    double otherS = cirS - moonS;
    double minS = min(otherS, moonS);
    double percentage = minS * 100 / cirS;

    if (abs(percentage - p) <= 5) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}