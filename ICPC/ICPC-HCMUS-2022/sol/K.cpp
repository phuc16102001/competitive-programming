#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

int res = 0;
vector<string> a;
int n, k;

void test(string answer) {
    if (answer.length()==k) {
        int lowest = k;
        for (int i=0;i<n;i++){
            int score = 0;
            for (int j=0;j<k;j++) {
                if (a[i][j]==answer[j]) {
                    score++;
                }
            }
            if (score<lowest) {
                lowest = score;
            }
        }
        if (lowest>res) res = lowest;
        return;
    }
    test(answer+'T');
    test(answer+'F');
}

int main() {
    cin >> n >> k;
    a.assign(n, "");
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    test("");
    cout << res;
}