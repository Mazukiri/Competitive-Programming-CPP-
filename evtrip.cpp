#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, Pmax, Dtarget;
int D[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> Pmax >> Dtarget;

    for (int i = 1; i<=n; i++) cin >> D[i];

    sort(D + 1, D + 1 + n);

    int currentP = Pmax;
    int ans = 0;

    for (int i = 1; i <=n; i++) {
        if (currentP >= D[i] - D[i - 1]) {
            currentP -= (D[i] - D[i - 1]);
            if (D[i] >= Dtarget) return cout << ans, 0;
            continue;
        }

        else {
            if (D[i] - D[i - 1] > Pmax) return cout << -1, 0;
            else {
                ans++;
                currentP = Pmax;
            }
        }
    }

    if (D[n] + currentP < Dtarget) {
        ans++;
        currentP = Pmax;
    }

    if (D[n] + currentP >= Dtarget) {
        return cout << ans, 0;
    }

    else return cout << -1, 0;
}