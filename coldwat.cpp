#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, c;
vector<int> adj[N];
bool vis[N];
queue<int> q;
int dist[N];

void BFS(){

    while (!q.empty()){

        int u = q.front();

        q.pop();
     
    
        for (int x: adj[u]) {
            if (dist[x] == 0) {
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

    cin >> n >> c;

    for (int i = 1; i<=c; i++){
        int u, v1, v2; cin >> u >> v1 >> v2;
        adj[u].push_back(v1);
        adj[u].push_back(v2);
    }

    dist[1] = 1;
    q.push(1);
    BFS();

    for (int i = 1; i<=n; i++){
        cout << dist[i] << '\n';
    }


}