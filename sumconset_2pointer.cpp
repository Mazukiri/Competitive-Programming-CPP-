#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, target;
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> target;

    int ans = 0, sum = 0, j = 0;

    for (int i = 1; i<=n; i++) cin >> A[i];

    for (int i = 1 ; i <= n; i++){

        while (j + 1 <= n && sum + A[j + 1] <= target) {
            sum += A[++j];
        }

        sum -= A[i];

        ans = max(ans, j - i + 1);
    }

    cout << ans;
}