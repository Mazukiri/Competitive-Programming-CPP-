#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
bool vis[N];
vector<II> ans;
vector<int> adj[N];


void BFS(int s){
    queue<II> q;

    q.push(II(0, s));

    while (!q.empty()){
        
        int dist = q.front().fi;
        int u = q.front().se;

        q.pop();

        vis[u] = true;

        ans.push_back(II(dist, u));

        for (int x : adj[u]){
            
            if (!vis[x]) {
                q.push(II(dist + 1, x));
                vis[x] = true;

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

    int n, m, s; cin >> n >> m >> s;

    for (int i = 1; i<=m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(s);

    sort(ans.begin(), ans.end());

    for (int i = 0; i<ans.size(); i++) cout << ans[i].se << " " << ans[i].fi << '\n';
}