#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, c;
vector<int> adj[N];
int dist[N];
queue<int> q;

void BFS() {
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
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

    cin >> n >> c;

    for (int i = 1; i<=c; i++) {
        int u, u1, u2; cin >> u >> u1 >> u2;
        adj[u].push_back(u1);
        adj[u].push_back(u2);
    }

    dist[1] = 1;
    q.push(1);
    BFS();

    for (int i = 1; i<=n; i++) {
        cout << dist[i] << '\n';
    }

}