#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()

// Đo thời gian
#define TIME_START auto start = chrono::high_resolution_clock::now()
#define TIME_END(name) auto end = chrono::high_resolution_clock::now(); \
    cout << name << " executed in " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " µs\n"

// 1. Bài toán đổi tiền (Change Coins)
int minCoins(vector<int>& c, int x) {
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < c.size(); i++) {
        for (int j = c[i]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }
    return dp[x] == 1e9 ? -1 : dp[x];
}

// 2. Bài toán xếp ba lô
int knapsack(vector<int>& w, vector<int>& v, int W) {
    int n = w.size();
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[W];
}

// 3. Lập lịch tham lam
int actSelect(vector<pii>& a) {
    sort(all(a), [](pii& x, pii& y) { return x.S < y.S; });
    int cnt = 0, last = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].F >= last) {
            cnt++;
            last = a[i].S;
        }
    }
    return cnt;
}

// 4-5. Prim & Kruskal
vector<vector<pii>> g;
vector<int> prim(int n) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> d(n, 1e9), p(n, -1), inMST(n, 0);
    d[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().S; pq.pop();
        if (inMST[u]) continue;
        inMST[u] = 1;
        for (auto [v, w] : g[u]) {
            if (!inMST[v] && w < d[v]) {
                d[v] = w;
                pq.push({d[v], v});
                p[v] = u;
            }
        }
    }
    return p;
}

struct DSU {
    vector<int> p;
    DSU(int n) : p(n, -1) {}
    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (p[a] > p[b]) swap(a, b);
        p[a] += p[b];
        p[b] = a;
        return true;
    }
};

int kruskal(int n, vector<pair<int, pii>>& e) {
    sort(all(e));
    DSU dsu(n);
    int mst = 0, cnt = 0;
    for (auto [w, uv] : e) {
        if (dsu.join(uv.F, uv.S)) {
            mst += w;
            if (++cnt == n - 1) break;
        }
    }
    return mst;
}

// 6. Dijkstra
vector<int> dijkstra(int n, int s) {
    vector<int> d(n, 1e9);
    priority_queue<pii, vector<pii>, greater<>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du > d[u]) continue;
        for (auto [v, w] : g[u]) {
            if (d[v] > du + w) {
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

// 7. Huffman
struct HuffNode {
    char c; int f;
    HuffNode *l, *r;
    HuffNode(char c, int f) : c(c), f(f), l(nullptr), r(nullptr) {}
};
struct Cmp {
    bool operator()(HuffNode* a, HuffNode* b) { return a->f > b->f; }
};
HuffNode* huffBuild(const unordered_map<char, int>& freq) {
    priority_queue<HuffNode*, vector<HuffNode*>, Cmp> pq;
    for (auto [c, f] : freq) pq.push(new HuffNode(c, f));
    while (pq.size() > 1) {
        HuffNode *l = pq.top(); pq.pop();
        HuffNode *r = pq.top(); pq.pop();
        HuffNode *n = new HuffNode('\0', l->f + r->f);
        n->l = l; n->r = r;
        pq.push(n);
    }
    return pq.top();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    
    TIME_START;
    vector<int> c = {1, 3, 4}; int x = 6;
    cout << "Min coins: " << minCoins(c, x) << '\n';
    TIME_END("MinCoins");
    return 0;
}