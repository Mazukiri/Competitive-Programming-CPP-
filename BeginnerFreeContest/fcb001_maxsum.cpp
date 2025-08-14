#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int A[N], sum[N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        sum[i] = sum[i-1] + A[i];
    }

    int ans = sum[1];

    for (int i = 1; i<=n; i++) {
        for (int j = 0; j<i; j++) {
            int currSum = sum[i] - sum[j];
            ans = max(ans, currSum);
        }
    }

    cout << ans;
}