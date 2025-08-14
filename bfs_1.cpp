#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
#define II pair<int,int>
#define fi first
#define se second
int n, m, s;
vector<int> adj[N];
vector<II> ans;
bool vis[N];

void BFS(int start) {
    queue<pair<int, int>> q;  // Queue to store (node, distance)
    q.push({start, 0});
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front().first;
        int dist = q.front().second;
        q.pop();

        ans.push_back(II(dist, u));

        for (int x : adj[u]) {
            if (!vis[x]) {
                vis[x] = true;
                q.push({x, dist + 1});  // Push adjacent nodes with incremented distance
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m >> s;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(s);

    sort(ans.begin(), ans.end());

    for (int i = 0; i<ans.size(); i++) cout << ans[i].se << " " << ans[i].fi << '\n';
}
