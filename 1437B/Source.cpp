#include <iostream>
using namespace std;

int test(int n, string s, int cur) {
	int l = 0, r = n - 1;
	int lval = cur, rval = 1 - cur;
	int count = 0;

	while (l < r) {
		while (l<n && lval == s[l] - 48) {
			lval = 1 - lval;
			l++;
		}
		while(r>=0 && rval == s[r] - 48) {
			rval = 1 - rval;
			r--;
		}
		if (l < r) {
			count++;
			for (int i = l; i < (r - l) / 2 + l; i++) {
				swap(s[i], s[r - i]);
			}					   
			l++;
			r--;
		}
	}

	return count;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int a = test(n, s, 0);
	int b = test(n, s, 1);
	cout << min(a, b) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}