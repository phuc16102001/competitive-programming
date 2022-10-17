#include <iostream>
using namespace std;

void solve() {
	string s;
	cin >> s;
	
	if (s.length() > 10) {
		cout << s[0] << s.length() - 2 << s[s.length() - 1];
	}
	else {
		cout << s;
	}
	cout << endl;
}


int main() {
	int n;
	cin >> n;

	while (n--) {
		solve();
	}
}