#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int diff = count(s.begin(), s.end(), 'a') - count(s.begin(). s.end(), 'b');

        int pre = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < s.size(); i++) {
            pre += s[i] == 'a' ? 1 : -1;
            if (mp.count(pre - D))
            mp[pre] = i;
        } 
    }
}