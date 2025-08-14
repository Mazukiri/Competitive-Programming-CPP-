#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int dem[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    int ans = 1;

    for (int i = 1; i<=n; i++){

        int x, d; cin >> x >> d;
        for (int j = x; j<=x+d; j++) {
            
            if (dem[j] < 1) dem[j]++;
            else {
                ans++;
                for (int k = j; k<=x; k++) dem[j]++;
                continue;
            }
        }
    }
    cout << ans;
}