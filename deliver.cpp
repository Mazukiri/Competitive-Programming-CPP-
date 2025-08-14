#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
vector<int> adj[N];
int dist[N];
bool vis[N];
queue<int> q;

void BFS(){
    q.push(1);
    dist[1] = 0;
    vis[1] = 1;

    while (!q.empty()){
        
        int u = q.front();
        q.pop();

        for (int x: adj[u]){
            if (!vis[x]){
                vis[x] = 1;
                q.push(x);
                dist[x] = dist[u] + 1;
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

    int n, m, q; cin >> n >> m >> q;

    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS();

    while (q--){
        int u; cin >> u;
        cout << dist[u] <<'\n';
    }
}