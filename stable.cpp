#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
set<int> adj[N];
int dist[N];
queue<int> q;
bool vis[N];
int cnt[N];

void BFS(){
    while (!q.empty()){

        int u = q.front();
        q.pop();

        for (int x: adj[u]) {
             {
                if (dist[x] == dist[u] + 1) {
                    cnt[x] += cnt[u];
                }

                else if (dist[x] > dist[u] + 1) {
                    dist[x] = dist[u] + 1;
                    cnt[x] = cnt[u];
                } 
                if (!vis[x]) {
                    q.push(x);
                    vis[x] = 1;
                }

                if (cnt[x] > 1) cnt[x] = 2;
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

    //Đếm số đường đi ngắn nhất từ s --> v bất kỳ

    int n, m, s; cin >> n >> m >> s;

    for (int i = 1; i<=m; i++){
        int u, v; cin >> u >> v;
        adj[u].insert(v);
    }

    //tính cost các đỉnh từ s, đồng thời tính cnt[i]: số đường đi ngắn nhất từ s --> i
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 1; cnt[s] = 1; vis[s] = 1;
    q.push(s);
    BFS();

    // for (int i = 1; i<=n; i++) cout << dist[i] << " " << cnt[i] << '\n';

    int ans = 0;
    for (int i = 1; i<=n; i++) if (cnt[i] > 1) ans++;
    cout << ans;



}