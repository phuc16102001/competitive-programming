#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

string s;

int main() {
    cin >> s;
    for (int i=3;i>=0;i--){
        for (int j=0;j<4;j++) {
            if ((s[j]>>i)&1) {
                cout << "*";
            } else {
                cout << ".";
            }
            if (j==0||j==2) cout << " ";
            else if (j==1) cout << "   ";
        }
        cout << endl;
    }
}