#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
vector<int> adj[N];
queue<int> q;
int n, m, s, t; 
int dist[N];

void BFS(){

    while (!q.empty()){
        int u = q.front();
        q.pop();
        

        if (u == t) {
            cout << dist[t];
            return;
        }

        for (int v: adj[u]){
            if (dist[v] == 0 && v != s) {
                q.push(v);       
                dist[v] = dist[u] + 1;
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

    cin >> n >> m >> s >> t;

    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    q.push(s);
    //[3 2 1]
    BFS();

    if (dist[t] == 0 && s != t) cout << -1;



}