#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3 + 5, K = 18;
vector<int> adj[N];
int n, q, t;
int depth[N];
int par[N][K]; // par[u][k]: tổ tiên thứ 2^k của nút u

void dfs(int u) {
    for (int v : adj[u]) {
        if (v != par[u][0]) {
            depth[v] = depth[u] + 1;
            par[v][0] = u; // gán cha trực tiếp
            dfs(v);        // tiếp tục duyệt đệ quy
        }
    }
}

void preprocess() {
    for (int k = 1; k < K; ++k) { // k là số bước nhảy (2^k)
        for (int u = 1; u <= n; ++u) {
                par[u][k] = par[par[u][k - 1]][k - 1];
        } 
    }
}

int lca(int u, int v) {
    // Cân bằng độ sâu
    if (depth[u] < depth[v]) swap(u, v);

    for (int k = K - 1; k >= 0; --k) {
        if (depth[par[u][k]] >= depth[v]) {
            u = par[u][k];
        }
    }

    if (u == v) return u; // nếu u và v trùng nhau, trả về chính nó

    // Nhảy đến tổ tiên chung thấp nhất
    for (int k = K - 1; k >= 0; --k) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }

    return par[u][0]; // tổ tiên chung thấp nhất
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> t; 

    for (int numCase = 1; numCase <= t; numCase++) {

    

        cin >> n;
    
        for (int i = 1; i<=n; i++) {
            int k; cin >> k;
            for (int j = 1; j<=k; j++) {
                int x; cin >> x;
                adj[i].push_back(x);
            }
        }

    depth[0] = -1; // đặt độ sâu của nút gốc 0

    dfs(1);         // duyệt cây và khởi tạo tổ tiên trực tiếp
    preprocess();   // tính toán các tổ tiên xa hơn

    cin >> q;
    cout << "Case " << numCase << ":" << '\n';
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << " ";
        cout << '\n';
    }
    for (int i = 1; i<=n; i++) adj[i].clear();
}
}
