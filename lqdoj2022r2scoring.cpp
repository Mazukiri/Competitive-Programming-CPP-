#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
int n, k, ans;
ll dp[N], a[N];
vector<int> adj[N], nums;
bool vis[N];

ll f[N], g[N];

ll Pow(ll a, ll b, ll M)
{
    a %= M;
    if (b == 0)
        return 1;
    if (b == 1)
        return a % M;
    ll t = 1;
    while (b)
    {
        if (b & 1)
            t = t * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return t;
}

ll C(int k, int n)
{
    return f[n] * g[k] % MOD * g[n - k] % MOD;
}

void prepare()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = f[i - 1] * i % MOD;
    g[N - 1] = Pow(f[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i > 0; --i)
        g[i] = g[i + 1] * (i + 1) % MOD;
}

namespace sub1
{
    bool check()
    {
        if (nums.size() < n + 1)
            return false;

        // for (int i = 1; i <= n; i++)
        //     cout << nums[i] << " ";
        // cout << '\n';

        for (int u = 1; u <= n; u++)
        {
            for (int v : adj[u])
            {
                if ((a[v] < a[u] && nums[v] > nums[u]) || (a[v] > a[u] && nums[v] < nums[u]))
                {
                    return false;
                }
            }
        }

        return true;
    }

    void backtrack()
    {
        if (nums.size() == n + 1)
        {
            if (check())
            {
                ans++;
                return;
            }
        }

        for (int i = 1; i <= n; i++)
        {

            if (!vis[i])
            {
                vis[i] = true;
                nums.push_back(i);
                backtrack();
                nums.pop_back();
                vis[i] = false;
            }
        }
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

    if (fopen("SCORING.inp", "r"))
    {
        freopen("SCORING.inp", "r", stdin);
        freopen("SCORING.out", "w", stdout);
    }

    prepare();

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cout << f[i] << " " << g[i] << '\n';

    ans = 0;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    nums.push_back(0);

    if (n > k)
    {
        cout << 0;
        return 0;
    }

    if (k <= 10)
    {
        sub1::backtrack();
        cout << ans * C(n, k) % MOD;
    }

    // cout << C(7, 9);

    /*
    Chứng minh sau khi định hướng lại cạnh cho đồ thị, đường đi từ nút 1 tới tất cả các nút lá
    đều tăng dần về điểm (điểm trong 1 -> k).
    */
}