#include <iostream>
#include <vector>
using namespace std;

#define LIMIT 30000 //d=10000
#define dat long

vector<dat> prime;
bool isPrime[LIMIT+1];

void era() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 0; i <= LIMIT;i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= LIMIT; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (int j = i * i; j <= LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int binFind(int l, int r, int k) {
    if (r<l) {
        if (prime[r]<k) {
            return l;
        }
        return r;
    } 

    int mid = (l + r) / 2;
    if (prime[mid]==k) {
        return mid;
    }
    if (prime[mid]>k) {
        return binFind(l, mid - 1, k);
    }
    if (prime[mid]<k) {
        return binFind(mid + 1, r, k);
    }

    return -1;
}

void solve() {
    int d;
    cin >> d;

    //(1,x,y,x*y) with x and y are primes such that x-1>=d and y-x>=d
    int x = prime[binFind(0,prime.size()-1,1 + d)];
    int y = prime[binFind(0,prime.size()-1,x + d)];
    // cout << x << " " << y << endl;
    cout << x * y << endl;
}

int main() {
    era();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}