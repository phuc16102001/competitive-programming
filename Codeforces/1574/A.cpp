// #include <bits/stdc++.h>
// #include <iostream>
// #include <sstream>

// using namespace std;

// string a[51];
// int countN = 0;

// void genN(int n,int count, string s) {
//     if (countN==n) {
//         return;
//     }
//     if (count==n) {
//         countN+=1;
//         cout << s << endl;
//         return;
//     }
//     genN(n,count+1,"()"+s);
//     for (int i=0;i<s.length();i++) {
//         if (s[i]=='(') {
//             string x = s.substr(0,i+1);
//             string y = s.substr(i+1,s.length()-i-1);
//             // cout << x << " " << y << "\n";
//             genN(n,count+1,x+"()"+y);
//         }
//     }
// }

// int main(){
//     int nTest;
//     cin >> nTest;
//     while (nTest--) {
//         int n;
//         cin >> n;
//         countN=0;
//         genN(n,1,"()");
//     }
// }

//============================================
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

using namespace std;


void genN(int n) {
    string s = "";
    for (int i=0;i<n;i++) {
        s += "()";
    }
    for (int i=1;i<=n;i++) {
        cout << s << endl;
        if (i!=n){
            s = "("+s.substr(0,2*i)+s.substr(2*i+1);
        }
    }
}

int main(){
    int nTest;
    cin >> nTest;
    while (nTest--) {
        int n;
        cin >> n;
        genN(n);
    }
}

//============================================