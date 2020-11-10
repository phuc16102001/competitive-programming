#include <iostream>
#include <vector>
using namespace std;

bool isPrime[1001];

void era(int limit) {
    isPrime[0]=isPrime[1]=false;
    for (int i=2;i<=limit;i++){
        isPrime[i]=true;
    }
    for (int i=2;i*i<=limit;i++){
        if (isPrime[i]){
            for (int j = i*i; j<=limit;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

int findPrime(int n) {
    //find k that k not prime and k+(n-1) is prime
    int k=0;
    while (isPrime[k] || !isPrime[k+n-1]){
        k++;
    }
    return k;
}

void solve() {
    int n;
    cin >> n;
    
    int k = findPrime(n);

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==j) {
                if (i==n-1) {
                    cout << k << endl;
                } else {
                    cout << 1 << " ";
                }
            } else {
                if (i==n-1 || j==n-1) {
                    cout << 1 << " ";
                } else {
                    cout << 0 << " ";
                }
                if (j==n-1) {
                    cout << endl;
                }
            }
        }
    }
}

int main(){
    era(1000);
    int t;
    cin >> t;
    while (t--) solve();
}