#include <bits/stdc++.h>
#include <stdio.h>

#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<ll, ll>

ll hash_pair(pii pair) {
    ll mask = pair.first;
    ll empty = pair.second;  // value from 0-25, so least 8 bits
    return ((mask << 8) + empty);
}

// map[hash({mask, empty})] = count
unordered_map<ll, ll> cnt;
vector<string> odd, even;
ll ret = 0;

int main() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() % 2) {
            odd.pb(s);
        } else {
            even.pb(s);
        }
    }

    for (ll i = 0; i < even.size(); i++) {
        string s = even[i];
        vector<ll> distributed(26, 0);

        // Distributed count
        for (ll j = 0; j < s.length(); j++) {
            distributed[s[j] - 'a']++;
        }

        // Create mask
        bitset<26> mask;
        for (ll j = 0; j < 26; j++) {
            mask.set(j, distributed[j] % 2);
        }

        // Count combination
        for (ll j = 0; j < 26; j++) {
            if (distributed[j]!=0) continue;
            
            bitset<26> new_mask = mask;
            new_mask.set(j, 0);
            ll hashed = hash_pair({new_mask.to_ulong(), j});
            cnt[hashed]++;
        }
    }

    for (ll i = 0; i < odd.size(); i++) {
        string s = odd[i];
        vector<ll> distributed(26, 0);

        // Distributed count
        for (ll j = 0; j < s.length(); j++) {
            distributed[s[j] - 'a']++;
        }

        // Create mask
        bitset<26> mask;
        for (ll j = 0; j < 26; j++) {
            mask.set(j, distributed[j] % 2);
        }

        // Calculate sum
        for (ll j = 0; j < 26; j++) {
            if (distributed[j] != 0) continue;

            bitset<26> new_mask = ~mask;
            new_mask.set(j, 0);
            ll hashed = hash_pair({new_mask.to_ulong(), j});
            ret += cnt[hashed];
        }
    }

    cout << ret;
}