#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define ll long long
#define pii pair<int,int>

vector<int> a(MAXN);
ll numPair;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.begin()+n);
    
    vector<int> value;
    vector<int> freq;
    int fi, se;
    fi = a[0];
    se = 1;
    for (int i=1;i<n;i++){
        if (fi==a[i]) {
            se++;
        } else {
            value.push_back(fi);
            freq.push_back(se);
            fi=a[i];
            se=1;
        }
    }
    value.push_back(fi);
    freq.push_back(se);

    int cnt = 0;
    for (int i=0;i<value.size();i++){
        while (freq[i]>0){
            freq[i]--;
            numPair = value[i]*x;
            int index = lower_bound(value.begin(),value.end(),numPair)-value.begin();
            if (index==value.end()-value.begin() || value[index]!=numPair){
                cnt++;
            } else {
                if (freq[index]>0) {
                    freq[index]--;
                } else {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}