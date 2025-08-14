#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int m, n, s0;
int dist[N];
int a[N], b[N];
bool vis[N];

void BFS(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty()) {
        int u = q.front(); // lấy phần tử đầu queue (được push vào sớm nhất)
        q.pop(); // xóa giá trị vừa lấy
        for (int i = 1; i<=n; i++) {
            
            int v = (u * a[i] + b[i])%m;
            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                vis[v] = 1;
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

    cin >> m >> n >> s0;

    for (int i = 1; i<=n; i++) cin >> a[i] >> b[i];

    //BFS đường đi ngắn nhất từ s0 --> 0;

    BFS(s0);

    if (dist[0] != 0) cout << dist[0]; else cout << -1;
}