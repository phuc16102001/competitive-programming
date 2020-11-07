#include <iostream>
#include <cmath>
using namespace std;

int a[100001];

int getLength(int n) {
	int count = 1;
	while (n > 1) {
		count++;
		n >>= 1;
	}
	return count;
}

void heapify(int a[], int n, int root) {
	int largest = root;
	int c1 = 2 * root + 1;
	int c2 = 2 * root + 2;

	if (c1<n && a[c1]>a[largest]) largest = c1;
	if (c2<n && a[c2]>a[largest]) largest = c2;
	if (largest != root) {
		swap(a[largest], a[root]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n) {
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(a, n, i);
	}

	for (int i = n-1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

long long sigma(long long n) {
	long long num = (n * (n + 1));
	return num / 2;
}

void solve() {
	int n, amax = 0;
	cin >> n;
	for (int i = 0; i < n; cin >> a[i++]);

	for (int i = 0; i < n; i++) {
		a[i] = getLength(a[i]);
	}

	heapSort(a, n);

	long long sum = 0;
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			sum += sigma(count-1);
			count = 0;
		}
		count++;
	}
	sum += sigma(count - 1);
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}