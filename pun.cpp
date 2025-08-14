#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int MOD = (int)(1e9+7);
const int BASE = (int)(257);
const int N = (int)(5005);
int p[N], h[2][N];
int n;
string s;
map<int, int> countSubstrings;
vector<int> subStringsIndex;
II gethash(int l, int r) {
    return (h[r] - (h[l-1] * p[r-l+1])%MOD + MOD) %MOD,
            h[r] - (h[l-1] * p[r-l+1])%MOD + MOD) %MOD2;

}

bool check(int len){
    
    countSubstrings.clear();
    subStringsIndex.clear();

    for (int i = 1; i + len - 1 <= n; i++) 
    {
        int index = gethash(i, i + len - 1);
        subStringsIndex.push_back(index);
        
        // cout << index << '\n';

        if (i > len) countSubstrings[subStringsIndex[i - len - 1]]++;

        if (countSubstrings[index] == 1) return true;
        
    }

    return false;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n; cin >> s;

    p[0] = 1;
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i-1] * BASE) %MOD;
    h[0] = 0;
    for (int i = 1; i <= n; ++i)
        h[i] = (h[i-1] * BASE %MOD + (s[i-1])) %MOD;

    int ans = 0;

    int l = 1, r = s.size();

    while (l<=r) {
        
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }

        else r = mid - 1;
    }

    // cout << check(1) << " " << check(2);

    cout << ans;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    
}