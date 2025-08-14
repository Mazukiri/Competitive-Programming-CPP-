#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

struct Edge {
    int to, index;
};

int color[N];
int degree[N];

vector<Edge> adj[N];

void DFS(int node, int parent_color) {
    int current_color = 1;

    for (Edge edge : adj[node]) {

        if (color[edge.index] == 0) {

            if (current_color == parent_color) {
                current_color++;
            }
        
            color[edge.index] = current_color;

            DFS(edge.to, current_color);
        
            current_color++;
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n; 
    for (int i = 1; i<=n-1; i++) {

        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    int max_degree = 0;

    for (int i = 1; i<=n; i++) {
        max_degree = max(max_degree, degree[i]);
    }

    DFS(1, 0);
    
    cout << max_degree << '\n';

    for (int i = 1; i<= n - 1; i++) {
        cout << color[i] << '\n';
    }
}