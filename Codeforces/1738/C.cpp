#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pii>
#define forf(i,a,b) for(int i=a;i<=b;i++)
#define forb(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define min(a,b) (a>b?b:a)
#define pb push_back
#define ALICE 1
#define BOB 0
#define EVEN 1
#define ODD 0

int d[2][2][101][101];

int find(int player, int win, int nEven, int nOdd) {
    if (d[player][win][nEven][nOdd]!=-1) return d[player][win][nEven][nOdd];
    int res=-1;

    if (nEven==0 && nOdd==0){
        if (win==EVEN) {
            res=ALICE;
        } else {
            res=BOB;
        }
    } else

    if (nEven==0) {
        if (player==ALICE) {
            res=find(BOB, 1-win, nEven, nOdd-1);
        } else {
            res=find(ALICE, win, nEven, nOdd-1);
        }
    } else

    if (nOdd==0) {
        res=find(1-player, win, nEven-1, nOdd);
    } else {
        if (player==BOB) {
            int res1=find(ALICE, win, nEven-1, nOdd);
            int res2=find(ALICE, win, nEven, nOdd-1);
            if (res1==BOB || res2==BOB) res=BOB;
            else res=ALICE;
        } else {
            int res1=find(BOB, win, nEven-1, nOdd);
            int res2=find(BOB, 1-win, nEven, nOdd-1);
            if (res1==ALICE || res2==ALICE) res=ALICE;
            else res=BOB;
        }
    }
    d[player][win][nEven][nOdd]=res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int nOdd =0;
    int nEven =0;

    forf(i,0,n-1) {
        int t;
        cin >> t;
        if (t%2) {
            nOdd++;
        } else {
            nEven++;
        }
    }
    if (find(ALICE,EVEN,nEven,nOdd)==ALICE) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

int main() {
    forf(x,0,1){
        forf(y,0,1){
            forf(z,0,100){
                forf(t,0,100){
                    d[x][y][z][t] = -1;
                }
            }
        }
    }
    int n;
    cin >> n;
    while (n--)solve();
}