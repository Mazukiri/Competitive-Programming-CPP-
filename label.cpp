#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int INF = 1e18;
vector<int> adj[N];
vector<int> adj2[N];
int low[N], num[N], tail[N];
int id[N], cnt[N];
stack<int> st;
int F[N];
int scc;
int n, m;
int timeDFS;

void dfs(int u, int par){
    st.push(u);
    num[u] = ++timeDFS;
    low[u] = num[u];

    for (int v : adj[u]){
        if (v == par) {
            continue;
        }
        
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[v], low[u]);
        }

        else {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        ++scc;
        int v;
        do {
            v = st.top(); st.pop();
            id[v] = scc;
            num[v] = INF;
        }  while (v != u);
    }

    tail[u] = timeDFS;
}

void solve(int u, int par){
    if (cnt[u] > 1) F[u] = -1;

    for (int v: adj2[u]) if (v != par) {
        if (F[u] == -1) {
            F[v] = -1;
        }

        else {
            F[v] += F[u];
            if (F[v] >= 2) F[v] = 2;
        }
    
        solve(v, u);    
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }    

    dfs(1, 1);

    for (int u = 1; u<=n; u++){
        for (int v : adj[u]){
            if (id[u] != id[v]){
                adj2[u].push_back(v);
            }

            if (u == v) //khuyen
            cnt[id[u]]++;
            
        }
        cnt[id[u]]++; 
    }

    for (int i = 1; i<=n; i++) cout << id[i] << " "; 

    cout << '\n';

    F[id[1]] = 1;

    solve(id[1], -1);

    for (int i = 1; i<=n; i++) cout << F[id[i]] << " ";

    


}