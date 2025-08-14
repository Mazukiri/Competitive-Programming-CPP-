#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, q, a[N];

struct Node
{
    int sum;
    int add_lazy, mul_lazy;

    Node()
    {
        sum = 0;
        add_lazy = 0;
        mul_lazy = 1;
    }
} st[N * 4];

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id].sum = a[l] % MOD;
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id].sum = (st[id * 2].sum + st[id * 2 + 1].sum) % MOD;
}

void down(int id, int l, int r)
{
    if (st[id].mul_lazy == 1 && st[id].add_lazy == 0)
        return;

    int mid = (l + r) / 2;

    for (int child : {id * 2, id * 2 + 1})
    {
        st[child].sum = (st[child].sum * st[id].mul_lazy) % MOD;
        st[child].sum = (st[child].sum + st[id].add_lazy * ((child == id * 2) ? (mid - l + 1) : (r - mid))) % MOD;

        st[child].mul_lazy = (st[child].mul_lazy * st[id].mul_lazy) % MOD;
        st[child].add_lazy = (st[child].add_lazy * st[id].mul_lazy + st[id].add_lazy) % MOD;
    }

    st[id].mul_lazy = 1;
    st[id].add_lazy = 0;
}

void update(int id, int l, int r, int u, int v, int type, int val)
{
    if (r < u || v < l)
        return;

    if (u <= l && r <= v)
    {
        if (type == 1)
        { // cộng
            st[id].add_lazy = (st[id].add_lazy + val) % MOD;
            st[id].sum = (st[id].sum + val * (r - l + 1)) % MOD;
        }
        else if (type == 2)
        { // nhân
            st[id].sum = (st[id].sum * val) % MOD;
            st[id].mul_lazy = (st[id].mul_lazy * val) % MOD;
            st[id].add_lazy = (st[id].add_lazy * val) % MOD;
        }
        else if (type == 3)
        { // gán
            st[id].sum = (val * (r - l + 1)) % MOD;
            st[id].mul_lazy = 0;
            st[id].add_lazy = val;
        }
        return;
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, type, val);
    update(id * 2 + 1, mid + 1, r, u, v, type, val);

    st[id].sum = (st[id * 2].sum + st[id * 2 + 1].sum) % MOD;
}

int get(int id, int l, int r, int u, int v)
{
    if (r < u || v < l)
        return 0;

    if (u <= l && r <= v)
    {
        return st[id].sum;
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    int left = get(id * 2, l, mid, u, v);
    int right = get(id * 2 + 1, mid + 1, r, u, v);
    return (left + right) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 4)
        {
            int l, r;
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << '\n';
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, type, x);
        }
    }

    return 0;
}
