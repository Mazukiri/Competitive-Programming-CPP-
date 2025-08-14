#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;
int sum[N];
int A[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i<=n; i++) cin >> A[i];

    int index1 = 1;
    int index2 = k;

    int sum = 0;

    for (int i = 1; i<=index2; i++) sum += A[i];

    int ans = sum;

    while (index2 <= n) {
        
        sum -= A[index1];

        index2++;

        sum += A[index2];
        
        index1++;

        ans = max(ans, sum);
        
    }

    cout << ans;

}