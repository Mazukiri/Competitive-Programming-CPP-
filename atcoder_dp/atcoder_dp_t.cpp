#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e3 + 5;
ll dp[N][N];
ll pre[N];
const ll MOD = 1e9 + 7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("_ab.inp", "r"))
    {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    // dp[i][j] : Số cách điền hoán vị i số đầu tiên sao cho số cuối cùng là j mà thỏa mãn i - 1 quan hệ
    //  Các ô đầu tiên chỉ điền từ 1-> i, không điềun số lớn hơn

    dp[1][1] = 1;

    int n;
    string s;

    cin >> n;
    cin >> s;

    pre[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (s[i - 2] == '<')
            {
                // for (int k = 1; k < j; k++)
                // {
                //     dp[i][j] += dp[i - 1][k];
                // }
                dp[i][j] += pre[j - 1];
                dp[i][j] %= MOD;
            }

            else
            {
                // for (int k = j; k <= n; k++)
                // {
                //     dp[i][j] += dp[i - 1][k];
                // }
                dp[i][j] += pre[i - 1] - pre[j - 1];
                dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }

        for (int j = 1; j <= i; j++)
        {
            pre[j] = pre[j - 1] + dp[i][j];
            pre[j] %= MOD;
        }
    }

    ll ans = 0;

    // for (int i = 1; i <= n; i++)
    //     ans += dp[n][i];

    cout << pre[n];
}