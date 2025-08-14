#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define INF -999999999999999;
const int N = 1e6 + 5;
int A[N], prefSum[N], prefMin[N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1; i<=n; i++) {
        prefSum[i] = prefSum[i - 1] + A[i];
        prefMin[i] = min(prefMin[i - 1], prefSum[i]);
    }

    int ans = INF;

    for (int i = 1; i<=n; i++) ans = max(ans, prefSum[i] - prefMin[i-1]);

    cout << ans;
}