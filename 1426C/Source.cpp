#include <iostream>
using namespace std;

int runner = 2;
int a[100000001];
int b[100000001];

void solve() {
	a[1] = 0;
	int n;
	cin >> n;
	while (runner <= n) {
		a[runner] = a[runner / 2] + 1;
		if (runner % 2 == 1) a[runner]++;
		b[runner] = runner/2;

		for (int i = 1; i <= runner/2; i++) {
			int k = a[i] + a[runner - i] + 1;
			if (runner % 2 == 1) k++;
			if (a[runner] > k) {
				a[runner] = k;
				b[runner] = i;
			}
		}

		runner++;
	}
	//cout << a[n] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();

	for (int i = 1; i < 43; i++) {
		cout << i << " " << a[i] << " " << b[i] << endl;
	}
}