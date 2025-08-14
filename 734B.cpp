#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;

    long long ans = 0;

    ans += min(min(k2, k5), k6) * 256;

    k2 -= min(min(k2, k5), k6);

    ans += 32 * min(k2, k3);

    cout << ans;
    
}