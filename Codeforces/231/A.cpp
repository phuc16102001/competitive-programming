#include <iostream>
using namespace std;

int main() {
	int n;
	int cc = 0;
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		cc += ((a + b + c > 1) ? 1 : 0);
	}
	cout << cc;
}