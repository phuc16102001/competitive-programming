#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define uint unsigned int
#define MOD 1000000007

int n, d;
vector<string> a;
vector<ll> f;
vector<ll> cnt(16, 0);
ll res = 0;

ll getMod(ll a, ll m) {
    while (a < 0) a += m;
    return a % m;
}

int getValue(char c) {
    if (c == '@') return 36;
    if ('a' <= c && c <= 'z') return c - 'a';
    return c - '0' + 26;
}

int hashString(string x) {
    int p = 1;
    int res = 0;
    for (int i = x.length() - 1; i >= 0; i--) {
        res += p * getValue(x[i]);
        p *= 37;
    }
    return res;
}

uint getMask(int hashValue) {
    int p = 37 * 37 * 37;
    uint nMask = 0;
    while (p) {
        int params = hashValue / p;
        nMask <<= 1;
        if (params == 36) {
            nMask |= 1;
        }
        hashValue -= params * p;
        p /= 37;
    }
    return nMask;
}

void distribute(string a, int pos, int d) {
    if (d == 0) {
        int hashValue = hashString(a);
        // cout << hashValue << endl;
        f[hashValue]++;
        return;
    }
    int lastPos = a.length() - d + 1;
    for (int i = pos; i < lastPos; i++) {
        string maskString = a.substr(0, i) + '@' + a.substr(i + 1);
        distribute(maskString, i + 1, d - 1);
    }
}

ll getComplement(uint nMask, int pos, int factor) {
    // cout << nMask << " " << pos << " " << factor << " " << cnt[nMask] << endl;
    ll nSum = 0;
    for (int i = pos; i < 4; i++) {
        if ((nMask >> (3 - i)) & 1) {
            uint bitFlip = ~(1 << (3 - i));
            uint newMask = nMask & bitFlip;
            nSum = nSum + getComplement(newMask, i + 1, -factor);
        }
    }
    int currentValue = factor * cnt[nMask];
    return currentValue + nSum;
}

void findSol(uint nMask, int pos, int nDifferent) {
    if (nDifferent == 0) {
        ll newSolution = getComplement(nMask, 0, 1);
        // cout << "FIND SOL: " << nMask << " " << newSolution << endl;
        res = res + newSolution;
        return;
    }
    for (int i = pos; i < 4; i++) {
        findSol(nMask | (1 << (3 - i)), i + 1, nDifferent - 1);
    }
}

fstream fin;

int main() {
    int n, d;
    // string nTest;
	// cin >> nTest;
	// fin.open("input"+nTest+".inp", ios::in);
    cin >> n >> d;

    f.assign(1874161, 0);
    vector<string> a(n, "");
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1; j <= 4; j++) {
            distribute(a[i], 0, j);
        }
    }

    for (int i = 0; i < 1874161; i++) {
        if (f[i]) {
            uint nMask = getMask(i);
            // cout << i << " " << f[i] << " " << nMask << endl;
            ll nChoice = f[i] * (f[i] - 1);
            nChoice = nChoice/2;  // nChoice /= 2;
            cnt[nMask] += nChoice;
        }
    }

    // for (int i=0;i<16;i++) {
    // 	int tmp = i;
    // 	string s = "";
    // 	for (int j=0;j<4;j++) {
    // 		if (tmp&1) s='1'+s;
    // 		else s='0'+s;
    // 		tmp >>= 1;
    // 	}
    // 	cout << s << " " << cnt[i] << endl;
    // }

    findSol(0, 0, d);

    cout << res;
}