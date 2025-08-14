#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Graph {
    int fi, se, side_length;

    bool operator>(const Graph& other) const {
        return fi > other.fi;
    }

    bool operator<(const Graph& other) const {
        return fi < other.fi;
    }
};

const int N = 10;

int n, m;

int flowrate[N]; int f[N]; double optimal[N];

vector<Graph> adj[N];

template<class X, class Y> bool mini(X& x, const Y y) {
    if (x > y) return x = y, 1;
    return 0;
}

void dijkstra(int node) {
    priority_queue<Graph, vector<Graph>, greater<Graph>> pq;
    //memset(f, 0x3f, sizeof f);
    
    //Khi tính toán liên quan tới số thực, không dùng memset
    fill(f, f + n + 1, 1e9);
    fill(flowrate, flowrate + n + 1, 1e9);
    pq.push({0, node});
    f[node] = 0;
    optimal[node] = 0;

    while (!pq.empty()) {
        Graph u = pq.top();
        pq.pop();

        if (u.fi != f[u.se]) continue;

        for (Graph v : adj[u.se]) {
            if (mini(f[v.se], f[u.se] + v.fi)) {
                pq.push({f[v.se], v.se});
                flowrate[v.se] = min(flowrate[u.se], v.side_length);
                if (f[v.se] > 0) 
                    optimal[v.se] = max(optimal[v.se], (double) flowrate[v.se]/f[v.se]);
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // if (fopen("_ab.inp", "r")) {
    //     freopen("_ab.inp", "r", stdin);
    //     freopen("_ab.out", "w", stdout);
    // }

    cin >> n >> m;
    
    // cout << n << " " << m << '\n';

    for (int i = 1; i<=m; i++) {
        int u, v, c, flowrates;
        cin >> u >> v >> c >> flowrates;
        
        adj[u].push_back({c, v, flowrates});
        adj[v].push_back({c, u, flowrates});

        //cout << u << " " << v << " " << c << " " << flowrates << '\n';
    }


    dijkstra(1);

    // for (int i = 1; i<=n; i++) cout << f[i] << " ";
    // cout << '\n';

    cout << trunc(optimal[n] * 1000000);
}