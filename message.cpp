int low[LimN], num[LimN];
vector<int> adj[LimN];
stack<int> st;

void dfs(int u) {
    num[u] = low[u] = ++timeDFS;
    st.push(u);
    for (auto v : adj[u]) {
        if (num[v]) {
            minimize(low[u], num[v]);
        }
        else {
            dfs(v);
            minimize(low[u], low[v]);
        }
    }
    if (low[u] == num[u]) {
        int v;
        do {
            v = st.top();
            st.pop();
            num[v] = INF;
        } while (v != u);
    }
}