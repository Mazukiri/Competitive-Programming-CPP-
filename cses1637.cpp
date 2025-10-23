#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
vector<int> nums;
int n;
ll dp[N];

void convert(int n)
{
    nums.clear();

    int target = n;

    while (target > 0)
    {
        int x = target % 10;
        nums.push_back(x);
        target /= 10;
    }
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

    cin >> n;

    memset(dp, 0x3f, sizeof dp);

    dp[n] = 0;

    for (int i = n; i >= 0; i--)
    {
        if (dp[i] == 0 && i != n)
            continue;
        convert(i);
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
            {
                dp[i - nums[j]] = min(dp[i - nums[j]], dp[i] + 1);
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << '\n';

    cout << dp[0];
}