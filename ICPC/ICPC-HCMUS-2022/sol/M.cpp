#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353
#define ll long long

vector<ll> dp;			// The number of cute number with length i

bool isCute(string s) {
	for (int i=0;i<s.length()-1;i++){
		if (s[i]==s[i+1]) return false;
	}
	return true;
}

// Get number of cute num in [s, 1000..0(s.len+1) - 1]  
// E.g: From 123 to 999
ll getToLatest(string s) {
	ll res = 0;
	for (int i=0;i<s.length();i++){
		ll factor;
		int num = s[i]-'0';
		bool stop = false;
		if (i==0){
			factor = 9-num;
		} else {
			int prev = s[i-1]-'0';
			factor = 9-num-(prev>num);
			stop = (prev==num);
		}
		res = (res+factor*dp[s.length()-i-1])%MOD;
		if (stop) return res;
	}
	if (isCute(s)) res = (res+1)%MOD;
	return res;
}

int main() {
	string l, r;
	cin >> l >> r;
	
	int nLeft = l.length();
	int nRight = r.length();
	dp.assign(nRight+1, 0);
	dp[0] = 1;
	for (int i=1;i<=nRight;i++){
		dp[i] = (9*dp[i-1])%MOD;
	}
	
	ll result = 0;
	ll toLeft = 0;
	for (int i=1;i<=nRight;i++) {
		result = (result + dp[i])%MOD;
		if (i==nLeft) toLeft = result;
	}
	
	ll exceptLeft = (toLeft - getToLatest(l));
	while (exceptLeft<0) exceptLeft += MOD;
	exceptLeft %= MOD;
	
	ll exceptRight = getToLatest(r) - isCute(r);
	while (exceptRight<0) exceptRight += MOD;
	exceptRight %= MOD;
	
	result -= exceptLeft + exceptRight;
	while (result<0) result += MOD;
	result %= MOD;
	cout << result;
}