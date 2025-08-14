#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int INF = 1e18;
const int N = 2505;

int n, m;
vector<II> adj[N]; 
int dist[N], trace[N];

void find_negative_cycle() {
    fill(dist, dist + N, 0);
    memset(trace, -1, sizeof trace);
    
    int cycle_start = -1;

    // Bellman-Ford để phát hiện chu trình âm
    for (int i = 1; i <= n; i++) {
        cycle_start = -1;
        for (int u = 1; u <= n; u++) {
            for (II edge : adj[u]) {
                int v = edge.se, w = edge.fi;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    trace[v] = u;
                    if (i == n) cycle_start = v; 
                }
            }
        }
    }

    // Nếu không có chu trình âm
    if (cycle_start == -1) {
        cout << "NO\n";
        return;
    }

    
    for (int i = 1; i <= n; i++) 
        cycle_start = trace[cycle_start]; 

    vector<int> cycle;
    for (int v = cycle_start;; v = trace[v]) {
        cycle.push_back(v);
        if (v == cycle_start && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    find_negative_cycle();
    
    return 0;
}
