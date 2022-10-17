#include <iostream>
using namespace std;

char x[3] = {'r','g','b'};
string s;

void solve(){
    cin >> s;
    bool ret = false;
    bool a[3]={0};

    for (int i=0;i<s.length();i++){
        if (s[i]=='r' || s[i]=='g' || s[i]=='b') {
            for (int j=0;j<3;j++){
                if (s[i]==x[j]){ 
                    a[j]=1;
                }
            }
        } else {
            char t = s[i]+32;
            bool exist = false;
            for (int j=0;j<3;j++){
                if (x[j]==t and a[j]==1) {
                    exist = true;
                    break;
                }
            }
            if (exist==false) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}