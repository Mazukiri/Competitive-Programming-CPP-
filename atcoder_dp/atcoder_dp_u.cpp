#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 17;
#define MASK(i) (int)(1LL << (i))
#define SET1(msk, i) (int)((msk) | MASK(i))
#define SET0(msk, i) (int)((msk) & ~MASK(i))
#define BIT(msk, i) (int)(((msk) >> (i)) & 1ll)
#define cnt1(x) (int)__builtin_popcountll((int)(x))
#define logg(x) (int)__builtin_clzll((int)(x))
#define pos1(x) (int)__builtin_ctzll((int)(x))
ll a[N][N];
ll n, dp[1 << N];

template <class X, class Y>
bool maxi(X &x, const Y y)
{
    if (x < y)
        return x = y, 1;
    return 0;
}

ll calc(ll msk2)
{

    ll res = 0;

    for (int i = 0; i < n; i++)
    {
        if (BIT(msk2, i) == 1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (BIT(msk2, j) == 1)
                {
                    res += a[i][j];
                }
            }
        }
    }

    return res;
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

    // mask = 0001111000111 => msk1 | msk2 = 0

    // mask = 110,
    // msk1 = 100, msk2 = 010
    // msk1 = 010, msk2 = 100
    // msk1 = 110, msk2 = 000

    cin >> n;

    int limit = (1 << n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(dp, -0x3f, sizeof dp);

    dp[0] = 0;

    for (int msk = 0; msk < limit; msk++)
        dp[msk] = calc(msk);

    for (int msk = 0; msk < limit; msk++)
    {

        // Sinh ra msk1 là tập con của msk, 110 ->

        // De lay ca chinh msk nua
        for (int msk1 = msk; msk1; msk1 = (msk1 - 1) & msk)
        {
            int msk2 = msk1 ^ msk;
            // cout << bitset<3>(msk2) << " " << calc(msk2) << '\n';
            maxi(dp[msk], dp[msk1] + dp[msk2]);
        }
    }

    ll ans = 0;

    for (int i = 0; i < limit; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
}