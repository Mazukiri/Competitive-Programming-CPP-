#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll dp1[N], dp2[N];
vector<int> adj[N];
int trace[N];
// dp1[u]: Do dai duong di dai nhat tu u xuong.
// dp2[u]: Do dai duong di dai nhi tu u xuong.
template <class X, class Y>
bool maxi(X &x, const Y y)
{
    if (x < y)
        return x = y, 1;
    return 0;
}
void dfs1(int u, int pre)
{
    dp1[u] = 0;
    dp2[u] = 0;

    for (int v : adj[u])
    {
        if (v != pre)
        {
            dfs1(v, u);
            if (dp1[u] < dp1[v] + 1)
            {
                dp2[u] = dp1[u];
                dp1[u] = dp1[v] + 1;
                trace[u] = v;
            }

            // vo dai nhi
            else if (dp2[u] < dp1[v] + 1)
            {
                dp2[u] = dp1[v] + 1;
            }
        }
    }
}

void dfs2(int u, int pre)
{

    for (int v : adj[u])
    {

        if (v != pre)
        {

            dfs2(v, u);

            if (trace[u] == v)
            {
                if ((dp1[v] < dp2[u] + 1))
                {
                    dp2[v] = dp1[v];
                    dp1[v] = dp2[u] + 1;
                    trace[v] = u;
                }

                else if (dp2[v] < dp2[u] + 1)
                {
                    dp2[v] = dp2[u] + 1;
                }
            }

            else
            {
                if (dp1[v] < dp1[u] + 1)
                {
                    dp2[v] = dp1[v];
                    dp1[v] = dp1[u] + 1;
                    trace[v] = u;
                }

                else if (dp2[v] < dp1[u] + 1)
                {
                    dp2[v] = dp1[u] + 1;
                }
            }
        }
    }

    // \
    // 1 -> dp1[v] = dp1[v], 1 + dp1[u]
    // - Located in the longest path from 1: dp1[v] = dp1[v], 1 + dp2[u]
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

    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 1);

    for (int i = 1; i < n; i++)
    {
        cout << dp1[i] << " " << dp2[i] << '\n';
    }

    int u = 1, v = adj[1][0];

    // dp1[u] va dp2[u] la nhung thong tin chac chan dung!
    /*
    A random node v that is child of node u:
    - Not located in the longest path from 1 -> dp1[v] = dp1[v], 1 + dp1[u]
    - Located in the longest path from 1: dp1[v] = dp1[v], 1 + dp2[u]
    */

    dfs2(1, 1);

    cout << '\n';

    for (int i = 1; i <= n; i++)
        cout << dp1[i] << '\n';
}