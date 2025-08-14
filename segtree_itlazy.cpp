#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
const int N = 1e6 + 5;
const int INF = 1e18;
struct Node
{
    int lazy; // giá trị T trong phân tích trên
    int val;  // giá trị lớn nhất.
} nodes[N * 4];

void down(int id)
{
    int t = nodes[id].lazy;
    nodes[id * 2].lazy += t;
    nodes[id * 2].val += t;

    nodes[id * 2 + 1].lazy += t;
    nodes[id * 2 + 1].val += t;

    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val)
{
    if (v < l || r < u)
    {
        return;
    }
    if (u <= l && r <= v)
    {
        // Khi cài đặt, ta LUÔN ĐẢM BẢO giá trị của nút được cập nhật ĐỒNG THỜI với
        // giá trị lazy propagation. Như vậy sẽ tránh sai sót.
        nodes[id].val += val;
        nodes[id].lazy += val;
        return;
    }
    int mid = (l + r) / 2;

    down(id); // đẩy giá trị lazy propagation xuống các con

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    nodes[id].val = max(nodes[id * 2].val, nodes[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -1LL * INF;
    }
    if (u <= l && r <= v)
    {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id); // đẩy giá trị lazy propagation xuống các con

    return max(get(id * 2, l, mid, u, v),
               get(id * 2 + 1, mid + 1, r, u, v));
    // Trong các bài toán tổng quát, giá trị ở nút id có thể bị thay đổi (do ta đẩy lazy propagation
    // xuống các con). Khi đó, ta cần cập nhật lại thông tin của nút id dựa trên thông tin của các con.
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) {
        int x; cin >> x;
        update(1, 1, n, i, i, x);
    }


    cin >> q;

    while (q--) {
        int typ; cin >> typ;
        
        if (typ == 1) {
            int x, y, val; cin >> x >> y >> val;
            update(1, 1, n, x, y, val);
        }

        else {
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
}