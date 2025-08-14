#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int dist[N];
int hasBox[N];
bool vis[N];
queue<int> q;
vector<int> adj[N];
void BFS(){
    q.push(1);

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int x: adj[u]){
            if (!vis[x]){
                vis[x] = true;
                dist[x] = dist[u] + 1;
                q.push(x);
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

    int n, m, c; cin >> n >> m >>c;

    for (int i = 1; i<=c; i++) {
        int u; cin >> u;
        hasBox[u] = 1;
    }

    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
    }

    dist[1] = 0; vis[1] = 1;

    BFS();

    int ans = 0;

    for (int i = 1; i<=n; i++) {
        if (hasBox[i]) ans += dist[i];
    }

    cout << ans;
}