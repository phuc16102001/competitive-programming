//Note: Cannot use quick sort, worst case O(N^2). Must use heap sort all cases O(NlogN)
//With quicksort the worst case is O(10^10) -> TLE

#include <iostream>
using namespace std;

int a[200001];

void heapify(int* a, int n, int root) {
    int c1, c2, smallest = root;
    c1 = 2 * root + 1;
    c2 = 2 * root + 2;

    if (c1<n && a[c1]<a[smallest]) {
        smallest = c1;
    }
    if (c2<n && a[c2]<a[smallest]) {
        smallest = c2;
    }
    if (smallest!=root) {
        swap(a[smallest], a[root]);
        heapify(a, n, smallest);
    }
}

void hSort(int* a, int n){
    //Heap construction
    for (int i = (n - 1) / 2; i >= 0;i--){
        heapify(a, n, i);
    }

    //Heap Sort
    for (int i = n - 1; i >= 0;i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 0;i<n;i++){
        cin >> a[i];
    }

    hSort(a, n);
    //Alice positive
    //Bob negative
    long long result = 0;
    for (int i = 0;i<n;i++){
        if (i%2==0) {
            //Alice
            if (a[i]%2==0) {
                result += a[i];
            }
        } else {
            //Bob
            if (a[i]%2==1) {
                result -= a[i];
            }
        }
    }

    if (result>0) {
        cout << "Alice\n";
    } else if (result<0) {
        cout << "Bob\n";
    } else {
        cout << "Tie\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}