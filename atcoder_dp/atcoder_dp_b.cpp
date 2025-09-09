#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define ll long long
int n, k;
const int N = 1e6 + 5;
ll A[N], cost[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cost[i] = LLONG_MAX;
    }

    cost[1] = 0;

    for (int i = 1; i <=n; i++) {
        for (int j = i; j <= i + k; j++) cost[j] = min(cost[j], cost[i] + abs(A[j] - A[i]));
    }

    cout << cost[n];
}