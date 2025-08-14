#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, Start, End;
int id[N];
vector<int> ans;

struct edge{
    int v;
    int id_u;
    int id_v;

    edge(int x, int id_prev_x, int id_x) {
        v = x;
        id_u = id_prev_x;
        id_v = id_x;
    }
};

vector<edge> adj[N];

void DFS(int u, int idx){
    
    ans.push_back(u);
    
    if (ans.size() >= N) return;

    for (int i = adj[u].size() - 1; i>=0; i--){
        
        edge e = adj[u][i];

        if (idx <= e.id_u) DFS(e.v, e.id_v);
        else return;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n; 
    cin >> Start >> End;

    id[0] = 1;

    for (int i = 1; i<=n; i++){
        
        int u, v; cin >> u >> v;
        
        if (id[u] > 0) {
            id[v]++;
            adj[u].push_back(edge(v, id[u], id[v]));
        }
    }

    DFS(0, 1);
    
    // for (int i = 0; i<ans.size(); i++) cout << ans[i] << " ";   

    for (int i = Start; i<End; i++){
        cout << ans[i % ans.size()] << " ";
    }


}