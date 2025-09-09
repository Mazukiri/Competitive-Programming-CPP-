#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e2 + 5;
const int K = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll dp[N][K];
ll A[K];
int n, k;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> k;

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) cin >> A[i];

    //Tuy thuoc vao dp[i][j] dinh nghia nhu the nao

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int nums = 0; nums <=  A[i]; nums++) {
                //Sau khi chia thang i xong da chia j vien keo ma o thang i
                //minh chia nums vien keo => i - 1 thang truoc do phai chia j - nums vien keo
                if (nums <= j) (dp[i][j] += dp[i - 1][j - nums]) %= MOD; 

            }
        }
    }

    cout << dp[n][k];
}