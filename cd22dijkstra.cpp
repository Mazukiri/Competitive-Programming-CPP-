#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int INF = 1e18;
#define II pair<int,int>
#define fi first
#define se second
int n, m;
priority_queue<II, vector<II>, greater<II> > pq; //min heap
vector<II> adj[N];
int dist[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;
    
    for (int i = 1; i<=m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) dist[i] = INF;

    dist[1] = 0;

    pq.push({dist[1], 1});

    while (!pq.empty()) {
        II startNode = pq.top();
        pq.pop();
        
        int u = startNode.second;
        //Vi khong co mang danh dau :< nen nut u co the push vao nhieu lan
        //co the ton tai nhieu hon mot lan trong pq nen chi lay lan tot nhat
        //de di

        if (startNode.fi == dist[u]) {

            for (II edge: adj[u]) {
                
                int v = edge.fi;
                int w = edge.se;

                if (dist[v] > dist[u] +  w) {
                    dist[v] = dist[u] +  w;
                    pq.push(make_pair(dist[v], v));
                }       
            }
        }
    }

    for (int i = 2; i<=n; i++) cout << dist[i] << " ";
    
}