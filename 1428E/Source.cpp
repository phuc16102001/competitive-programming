#include <iostream>
#include <cmath>
using namespace std;

int n, k, a[1000001];
long long sum = 0;

void heapify(int a[], int n, int root) {
	int smallest = root;
	int c1 = 2 * root + 1;
	int c2 = 2 * root + 2;

	if (c1<n && a[c1]<a[smallest]) smallest = c1;
	if (c2<n && a[c2]<a[smallest]) smallest = c2;
	if (smallest != root) {
		swap(a[smallest], a[root]);
		heapify(a, n, smallest);
	}
}

int binSearch(int a[], int l, int r, int key) {	 
	if (l>r) return r;
	int mid = (l + r) / 2;
	if (a[mid] == key) return mid;
	if (a[mid] > key) return binSearch(a, mid + 1, r, key);
	return binSearch(a, l, mid - 1, key);
}

void insert(int a[], int index, int key, int& n, int times) {
	for (int i = (n-1)+times; i > index; i--) {
		a[i] = a[i-1];
	}
	for (int i = index; i < index + times; i++) {
		a[i] = key;
	}
	n+=times;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; cin >> a[i++]);

	//Heap sort O(nlogn)
	for (int i = (n - 1) / 2; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n-1; i > 0; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}

	//Split and searching then insert
	int times = k-n;
	int runner = 0;
	while (times > 0) {
		int x, y, seg, next = 0;
		if (runner + 1 < n) {
			next = a[runner + 1];
		}

		if (next == 0) {	
			seg = times + 1;
			int x1 = floor(1.0 * a[runner] / seg);
			int x2 = ceil(1.0 * a[runner] / seg);
			int y1 = a[runner] - (seg - 1) * x1;
			int y2 = a[runner] - (seg - 1) * x2;
			if (abs(x1 - y1) > abs(x2 - y2)) {
				x = x2;
				y = y2;
			}
			else {
				x = x1;
				y = y1;
			}
		}
		else {
			seg = a[runner] / next + 1;
			x = (a[runner] / seg);
			y = a[runner] - (seg - 1) * x;
		}

		int indX = binSearch(a, runner, n - 1, x)+1;
		insert(a, indX, x, n, seg-1);
		int indY = binSearch(a, runner, n - 1, y)+1;
		insert(a, indY, y, n, 1);

		times -= seg-1;
		runner++;
	}
													   
	while (runner < n) {
		long long tmp = a[runner];
		tmp *= tmp;
		sum += tmp;
		runner++;
	}
	cout << sum;

	return 0;
}