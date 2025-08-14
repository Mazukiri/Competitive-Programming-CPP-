#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e3+5;
int n, a[N];
int dp[N], trace[N];

template<class X, class Y> bool maxi(X& x, const Y y) {
    if (x < y) return x = y, 1;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 0, pos = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = n; j > i; --j) {
            if (a[j] > a[i] && maxi(dp[i], dp[j] + 1)) {
                trace[i] = j;
            }
        }
        if (maxi(ans, dp[i])) {
            pos = i;
        }
    }

    vector<int> tr;
    tr.push_back(pos);
    while (trace[pos] != 0) {
        pos = trace[pos];
        tr.push_back(pos);
    }
    cout << tr.size() << '\n';
    for (int i: tr) cout << a[i] << ' ';

    return 0;
}
