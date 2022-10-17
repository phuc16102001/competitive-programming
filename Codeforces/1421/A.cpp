#include <iostream>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	int temp = (a ^ b);
	temp = ~temp;
	temp = (temp & a & b);
	cout << (a ^ temp) + (b ^ temp) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}