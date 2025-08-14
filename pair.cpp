#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;
pair<int, int> hocsinh[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i<=n; i++) cin >> hocsinh[i].second >> hocsinh[i].first;

    sort(hocsinh + 1, hocsinh + 1 + n, greater<pair<int, int>>());

    for (int i = 1; i<=k; i++) cout << hocsinh[i].second << '\n';

}