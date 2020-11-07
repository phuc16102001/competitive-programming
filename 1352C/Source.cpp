#include <iostream>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	int pre, cur;
	cur = k/n;
	pre = 0;
	if (cur != 0) {
		do {
			k += cur - pre;
			pre = cur;
			cur = k / n;
		} while (pre != cur);
	}
	cout << k << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}