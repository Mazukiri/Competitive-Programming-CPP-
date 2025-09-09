#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
string s;
int n;
ll pre[2][N];



ll calc(ll num0, ll num1)
{
    if (num0 > 0 && num1 > 0)
        return num0 * num1;
    if (num0 > 0 && num1 == 0)
        return num0 * num0;
    if (num0 == 0 && num1 > 0)
        return num1 * num1;
}

void sub2()
{
    ll ans = 0;

    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int right = i + len - 1, left = i;

            ll currSum = calc(pre[0][right] - pre[0][left - 1],
                              pre[1][right] - pre[1][left - 1]);

            ans += currSum;
        }
    }

    cout << ans << '\n';
    exit(0);
}

ll sub3(int n)
{
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {

        ans += 1ll * i * i * (n - i + 1);
    }

    return ans;
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

    cin >> s;

    n = s.size();

    s = " " + s;

    for (int i = 1; i <= n; i++)
    {
        pre[0][i] += pre[0][i - 1] + (s[i] == '0');
        pre[1][i] += pre[1][i - 1] + (s[i] == '1');
    }

    if (n <= 5000)
        sub2();

    int cnt0 = 0, cnt1 = 0;

    for (int i = 1; i < s.size(); i++)
    {
        cnt0 += (s[i] == '0');
        cnt1 += (s[i] == '1');
    }

    if (cnt0 == n || cnt1 == n)
    {
        cout << sub3(n);
        return 0;
    }

    int window = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i + 1])
            window++;
    }

    if (window == 1)
    {
        ll sum1 = ((pre[0][n] - pre[0][0]) + 1) * (pre[0][n] - pre[0][0]) / 2;
        ll sum2 = ((pre[1][n] - pre[1][0]) + 1) * (pre[1][n] - pre[1][0]) / 2;

        cout << sum1 * sum2 + sub3(pre[0][n] - pre[0][0]) + sub3(pre[1][n] - pre[1][0]);
    }
}