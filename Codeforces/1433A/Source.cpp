#include <iostream>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int k = (n % 10 - 1) * 10;
	int p = 0;
	while (n) {
		k += (++p);
		n /= 10;
	}
	cout << k << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}