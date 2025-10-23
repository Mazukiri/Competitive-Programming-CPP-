#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll cnt[N];
ll dp[N][21];
ll A[N];

int n, m;

template <class X, class Y>
bool mini(X &x, const Y y)
{
    if (x > y)
        return x = y, 1;
    return 0;
}

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

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    // dp[i][j] = đáp án tối ưu của việc chia i phần tử đầu tiên vào j nhóm

    // Lấy nhát cắt từ phải sang trái. Tại mỗi nhát cắt, ta tăng thêm cnt[x]++ với x là giá trị mới được thêm vào
    // dp[i][j - 1] =
    // 2 2 2 2 2 2 = 15

    const ll INF = 1e18;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            dp[i][j] = INF;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << '\n';
    // }

    /*
    dp[i][j]: Cách chia i phần tử đầu tiên vào j nhóm đạt kết quả tốt nhất
    dp1[i][j] = dp1[i][j - 1] + dp2[i][j - 1]

    
    
    */

    
    
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = cnt[A[i]]++ + dp[i - 1][1];
    }

    memset(cnt, 0, sizeof cnt);

    for (int j = 2; j <= min(m, i); j++)
    {
        //
        ll value = 0;

        cout << '\n';

        memset(cnt, 0, sizeof cnt);
    }
    for (int k = i; k >= 1; k--)
    {
        value += cnt[A[k]];
        mini(dp[i][j], dp[k - 1][j - 1] + value);
        ++cnt[A[k]];
        // cout << value + dp[k - 1][j - 1] << " ";

        for (int i = 1; i <= n; i++)
        {
            
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << '\n';
    // }

    cout << dp[n][m];
}