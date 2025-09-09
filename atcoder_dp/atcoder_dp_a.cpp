#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll A[N], cost[N];
int n;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cost[i] = LLONG_MAX;
    }

    cost[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        cost[i + 1] = min(cost[i + 1], cost[i] + abs(A[i + 1] - A[i]));
        cost[i + 2] = min(cost[i + 2], cost[i] + abs(A[i + 2] - A[i]));
    }

    cout << cost[n];




    
}