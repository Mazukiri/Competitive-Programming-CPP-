#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int cost[N][N];
int W[N];
int n;
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //Tham bậy

    cin >> n;   

    for (int i = 1; i<=n; i++) cin >> W[i];

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) cin >> cost[i][j];
    }

    sort(W + 1, W + n + 1);

    int ans = 1'000'000'000'000'000'000;

    for (int i = 1; i<=n; i++) {
        int newCost = 0;
        newCost += W[i];

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int currCost = min(W[j], cost[i][j]);
            newCost += currCost;
        }

        ans = min(ans, newCost);
    }

    cout << ans;
}