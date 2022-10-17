#include <iostream>
using namespace std;

//Size n
void heapify(int a[], int n, int root) {
	int largest = root;
	int c1 = root * 2 + 1;
	int c2 = root * 2 + 2;
	if (c1 < n && a[c1] > a[largest]) largest = c1;
	if (c2 < n && a[c2] > a[largest]) largest = c2;

	if (largest != root) {
		swap(a[root], a[largest]);
		heapify(a, n, largest);
	}
}

void heap(int a[], int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(a, n, i);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void solve() {
	int n,a[51];
	cin >> n;
	for (int i = 0; i < n; cin >> a[i++]);

	heap(a, n);

	int sum = 0, i = 0;
	bool haveZero = false;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum == 0) haveZero = true;
	}

	if (sum == 0) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	if (haveZero) {
		for (int i = n - 1; i >= 0; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}