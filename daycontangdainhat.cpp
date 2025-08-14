#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int A[N];
vector<int> dp(N, 1);
//dp[i]: Số lượng phần tử của dãy tăng dài nhất kết thúc tại vị trí i

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    

    int ans = 1;


    for (int i = 2; i<=n; i++){
        for (int j = 1; j<=i - 1; j++){

            if (A[i]>A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    cout << ans;
}