#include <iostream>
using namespace std;

int c = 0;

void place(int x, int y) {
	if (x == 0) return;
	if (x == 1) {
		c += y / 2;
		return;
	}
	else if (y%2==1) {
		c += y;
		x -= 2;
	}
	else {
		c += y / 2;
		x -= 1;
	}
	place(x, y);
}

int main() {
	int x, y;
	cin >> x >> y;
	place(x, y);
	cout << c;
}