#include <bits/stdc++.h>                                                                                                                                                                                      //logkit
using namespace std;
#define int long long

const int N = 21, MOD = 1e9+7;
int n, a[N][N];

int dp[N+1][1 << N];
// dp[i][msk]: số cách đế xếp cho i người đàn ông tiên 
// và trong đó đã chọn các phụ nữ được được bit 1 trong msk

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    memset(dp, 0, sizeof dp);
    
    dp[0][0] = 1;
    int lim = (1ll << N);
    for (int i = 1; i <= n; ++i) {
        // đã tính được tất cả dp[i - 1][0..lim-1]
        // đang chia cặp cho người đàn ông thứ i
        for (int msk = 0; msk < lim; ++msk) {
            for (int j = 0; j < n; ++j) {
                if ((msk >> j & 1) == 0 && a[i - 1][j]) {
                    (dp[i][msk | (1 << j)] += dp[i - 1][msk]) %= MOD;
                }
            }
        }
    }

    cout << dp[n][(1 << n) - 1];
    return 0;
}