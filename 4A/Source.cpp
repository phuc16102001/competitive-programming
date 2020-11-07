#include <iostream>
using namespace std;

int main() {
	int w;
	cin >> w;
	if (w <= 2) {
		cout << "NO";
		return 0;
	}

	cout << (w % 2 ? "NO" : "YES");
}