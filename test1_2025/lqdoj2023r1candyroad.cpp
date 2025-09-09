#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define ll long long
const int N = 5e5 + 5;
const ll MOD = 998244353;
int n, m;
ll A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("candyroad.inp", "r")) {
        freopen("candyroad.inp", "r", stdin);
        freopen("candyroad.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> A[i];

    ll realSum;

    if (m >= 1e8) {
        ll realSum1 = (1 + 1e8) *  1e8 / 2;
        realSum1 %= MOD;

        ll realSum2 = (1e8 + 1 + m) * (m - 1e8) / 2;
        realSum2 %= MOD;

        realSum = (realSum1 + realSum2) % MOD;
    }

    else {
        realSum = m * (m + 1) / 2;
        realSum %= MOD;
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ll currSum = realSum;

        unordered_map<int, bool> isExist;

        for (int j = i; j <= n; j++) {
            
            if (!isExist[A[j]]) {
                currSum -= A[j];
                isExist[A[j]] = true;
            }

            ans += currSum % MOD;
            ans %= MOD;
        }
    }

    cout << ans;
}