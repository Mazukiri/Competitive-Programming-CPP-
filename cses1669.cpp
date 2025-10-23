#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int start, ed;
vector<int> adj[N];
int pre[N];
int n, m;
bool flag = true;
vector<int> lst;

void found_cycle(int u)
{
    for (int v : adj[u])
    {
        if (!flag)
            break;

        if (pre[v] == 0)
        {
            pre[v] = u;
            found_cycle(v);
        }

        else if (v != pre[u])
        {
            start = v;
            ed = u;
            flag = false;
            return;
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

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == 0)
        {

            pre[i] = -1;
            found_cycle(i);
        }

        if (!flag)
        {
            lst.push_back(start);
            lst.push_back(ed);
            while (pre[ed] != start)
            {
                ed = pre[ed];
                lst.push_back(ed);
            }
            lst.push_back(start);
            break;
        }
    }

    // cout << start << " " << ed << '\n';

    if (lst.size() > 0)
    {
        cout << lst.size() << '\n';
        for (int i = 0; i < lst.size(); i++)
            cout << lst[i] << " ";
    }

    else
    {
        cout << "IMPOSSIBLE";
    }
}