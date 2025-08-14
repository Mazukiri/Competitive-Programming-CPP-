#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int A[N], cnt[N]; // cnt[i] là số cách tạo ra dãy con tăng dài nhất kế thúc tại i, có độ dài dp[i]
int dp[N];        // dp[i] là độ dài dãy con tăng dài nhất kết thúc tại i
const long long BASE = 20071008;
// dp counting thuong o duoi dang to hop ==> Nen thuong phai mod voi BASE

signed main()
{
    freopen("dp.inp", "r", stdin);
    freopen("dp.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> A[i];

    // khoi tao qhd
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        cnt[i] = 0;
    }

    // Length: Xem day con tang dai nhat co bao nhieu phan tu
    int length = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (int i = 1; i <= n; i++)
        length = max(dp[i], length);

    // cnt[1] = 1 vì dãy con tăng dài nhất của 1 là 1
    cnt[1] = 1;
    // Dem xem co bao nhieu cach tao ra day con tang dai nhat
    long long ans = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            // Kiem tra neu lay dp[j] co tao thanh dp[i] duoc khong
            // Nếu có, số cách tạo dp[i] = cnt[i] (cnt[i] += cnt[j] (biến cố độc lập)
            if (A[j] < A[i] && dp[j] + 1 == dp[i])
            {

                (cnt[i] += cnt[j]) %= BASE;
            }
        }

        if (cnt[i] == 0)
            cnt[i] = 1;
    }

    for (int i = 1; i <= n; i++)
        if (dp[i] == length)
        {

            // ans = ans + cnt[i]
            // ans = ans%BASE
            (ans += cnt[i]) %= BASE;
        }

    cout << ans;

    return 0;
}
