

#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
const int N = 1e5 + 5;
int n, q;
int A[N];
int cnt[N];
vector< vector<int> > prefixSum;
vector<int> appearances;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] <= n) cnt[A[i]]++;
    }

    //prefixsum
    for (int i = 1; i <= n; i++) {
        if (i > cnt[i]) continue;

        appearances.push_back(i);
        
        prefixSum.push_back(vector<int>(n + 5));
        
        for (int j = 1; j <= n; j++) {
            prefixSum.back()[j] = prefixSum.back()[j - 1] + (A[j] == i);
        }
    }

    //
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int ans = 0;
        for (int index = 0; index < appearances.size(); index++) {
            if (prefixSum[index][r] - prefixSum[index][l - 1] == appearances[index]) ans++;
        }
        cout << ans << '\n';
    }
    
}

