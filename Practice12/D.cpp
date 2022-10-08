#include<bits/stdc++.h>
using namespace std;

#define forf(i,a,b) for (int i=a;i<=b;i++)
#define ll long long
#define pb push_back
#define min(a,b) (a<b)?a:b

int n, m;
vector<int> p, x, d, marker;

int main() {
    cin >> n >> m;
    p.assign(n, 0);
    x.assign(m, 0);
    d.assign(n, 0);
    forf(i,0,n-1) cin >> p[i];
    forf(i,0,m-1) cin >> x[i];

    // Prefix sum
    d[0] = p[0];
    forf(i,1,n-1) d[i] = d[i-1]+p[i];

    // Create marker
    sort(x.begin(), x.end());
    marker.pb(1);
    forf(i,0,n-1) {
        int position = 100*i;
        int lower = lower_bound(x.begin(), x.end(), position) - x.begin();
        int upper = upper_bound(x.begin(), x.end(), position) - x.begin();

        lower -= 1;
        if (upper==x.end()-x.begin()) upper = m-1;

        int lowerDistance = abs(x[lower]-position);
        int upperDistance = abs(x[upper]-position);
        int distance = min(lowerDistance,upperDistance);

        int x1 = i*100 - distance + 1;
        int x2 = i*100 + distance - 1;
        if (x1>0) marker.pb(x1);
        if (x2<(n-1)*100) marker.pb(x2);
    }
    marker.pb((n-1)*100-1);
    sort(marker.begin(), marker.end());
    auto it = unique(marker.begin(), marker.end());
    marker.resize(it-marker.begin());

    // Debug
    // forf(i,0,marker.size()-1) cout << marker[i] << " ";
    // cout << endl;

    // Find max value
    int result = 0;
    forf(i,0,marker.size()-1) {
        int mid = marker[i];
        int lower = lower_bound(x.begin(), x.end(), mid) - x.begin();
        int upper = upper_bound(x.begin(), x.end(), mid) - x.begin();

        if (lower == m) lower = m-1;
        else if (x[lower]>=mid) {
            lower -= 1;
        }

        int left = (lower==-1) ? 0 : min(n-1,ceil(x[lower]*1.0/100));
        int right = (upper==m) ? n-1 : min(n-1,floor(x[upper]*1.0/100));
        int value = d[right]-d[left]+p[left];
        cout << mid << " " << left << " " << right << " " << value << endl;
        if (result<value) result = value;
    }
    cout << result << endl;
}