#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const long long N = 1e6 + 5;
int dem[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;

    memset(dem, 0, sizeof(dem));

    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        dem[x]++;
    }

    for (int i = 1; i<=1000000; i++){
        if (dem[i] > 0) {
            for (int j = 1; j<=dem[i]; j++) cout << i << " ";
    }

    //Counting sort: O(2n) -> O(n) = 2 * 10^6
    //Introsort: O(nlogn) -> 10^6 * 20 = 2 * 10^7
}
}