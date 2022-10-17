#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

vector<bool> isPrime;
vector<ll> prime;

void sieve(int n, int h) {
    isPrime.assign(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (ll i=2;i<=n;i++){
        if (isPrime[i]) {
            prime.pb(i);
            int primeSize = prime.size();
            if (primeSize>h) return;
            for (ll j=i*i;j<=n;j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int l, h;
    string s;
    cin >> l >> h >> s;
    sieve(2e6, h);

    int cnt = 0;
    for (int i=l-1;i<h;i++){
        bool valid = false;
        ll num = prime[i];
        string tmp = to_string(num);
        int lastPos = tmp.length()-s.length()+1;
        for (int i=0;i<lastPos;i++) {
            if (s == tmp.substr(i,s.length())){
                valid = true;
                break;
            }
        }
        if (valid) cnt++;
    }
    cout << cnt;
}