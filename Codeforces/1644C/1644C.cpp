#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001
#define INF int(1e9);
int a[MAXN];
int prefix[MAXN];
int dp[MAXN];   //Max sum of array len [i]

int calcPrefixSum(int l, int r){
    return prefix[r]-prefix[l]+a[l];
}

void solve(){
    int n, x;
    cin >> n >> x;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    prefix[0]=a[0];
    for (int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        dp[i] = -INF;
        for (int j=0;j<=n-i;j++){
            dp[i]=max(dp[i],calcPrefixSum(j,j+i-1));
        }
    }
    for (int k=0;k<=n;k++){
        int maxSum = -INF;
        for (int i=0;i<=n;i++){
            maxSum = max(maxSum,dp[i]+min(k,i)*x);
        }
        cout << maxSum << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}