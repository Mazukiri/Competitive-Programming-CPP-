#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k;
vector<int> adj[N];
int dist[N];
queue<int> q;
int ans;
vector<int> SickNess_town;

void BFS(int vertices){

    q.push(vertices);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: adj[u]) {
            if (dist[v] != dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i<SickNess_town.size(); i++) if (dist[SickNess_town[i]] > k) return;
    ans++;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("BV.inp", "r")) {
        freopen("BV.inp", "r", stdin);
        freopen("BV.out", "w", stdout);
    }

    cin >> n >> m >> k;

    for (int i = 1; i<=n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i<=m; i++) {
        int sickness_town; cin >> sickness_town;
        SickNess_town.push_back(sickness_town);
    }

    ans = 0;

    for (int i = 1; i<=n; i++){
        BFS(i);
        
    }

    cout << ans;


}
