#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int V[N], dp[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int sum = 0;

    for (int i = 1; i<=n; i++) {
        cin >> V[i];
        sum += V[i];
    }

    sort(V + 1, V + 1 + n);

    dp[0] = 1;

    for (int i = 1; i<=sum; i++){
        for (int j = 1; j<=n; j++){

            if (i - V[j] >= 0 && dp[i - V[j]] > 0)  dp[i]++;
        }
    }

    int ans = 0;

    for (int i = 1; i<=sum/2 + 1; i++) if (dp[i]/2 >= 2 && sum - 2*i >= 0 && dp[sum - 2*i] == 1) ans = i;

    cout << ans;

}