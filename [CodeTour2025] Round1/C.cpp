#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N = 2e5 + 5;
int n, q;
ll a[N];

int calc(int l, int r)
{
    return 1LL * (l + r) * (r - l + 1) / 2;
}
int seg[N * 4];
void build(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        seg[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
int cnt[N * 4], sum[N * 4];
// a[i] = i * x - (u - 1) * y
// a[i] = cnt[i] - sum[i]
// seg[l..r] = cnt[i]
void pushdown(int id, int l, int r)
{
    if (cnt[id] == 0 && sum[id] == 0)
        return;
    int mid = l + r >> 1;
    cnt[id << 1] += cnt[id];
    sum[id << 1] += sum[id];
    seg[id << 1] += cnt[id] * calc(l, mid) - sum[id] * (mid - l + 1);

    cnt[id << 1 | 1] += cnt[id];
    sum[id << 1 | 1] += sum[id];
    seg[id << 1 | 1] += cnt[id] * calc(mid + 1, r) - sum[id] * (r - mid);

    cnt[id] = sum[id] = 0;
}
// i = u..v: cnt[i] += i, sum[i] += u - 1;
// a[u] += 1, a[u + 1] += 2, a[u + 2] += 3, ..., a[v] += a[v - u + 1]
void update(int u, int v, int sign, int id = 1, int l = 1, int r = n)
{
    if (u <= l && r <= v)
    {
        cnt[id] += 1 * sign;
        sum[id] += (u - 1) * sign;
        seg[id] += sign * (calc(l, r) - (u - 1) * (r - l + 1));
        return;
    }
    if (l > v || r < u)
        return;
    pushdown(id, l, r);
    int mid = l + r >> 1;
    update(u, v, sign, id << 1, l, mid);
    update(u, v, sign, id << 1 | 1, mid + 1, r);
    seg[id] = seg[id << 1] + seg[id << 1 | 1];
}
// a[u] + a[u + 1] + a[u + 2] + ... + a[v]
int get(int u, int v, int id = 1, int l = 1, int r = n)
{
    if (u <= l && r <= v)
        return seg[id];
    if (l > v || r < u)
        return 0;
    pushdown(id, l, r);
    int mid = l + r >> 1;
    return get(u, v, id << 1, l, mid) + get(u, v, id << 1 | 1, mid + 1, r);
}

int seg2[N * 4], lazy[N * 4];
void pushdown1(int i, int l, int r)
{
    if (lazy[i] == 0)
        return;
    int m = l + r >> 1;
    seg2[i << 1] += lazy[i] * (m - l + 1);
    seg2[i << 1 | 1] += lazy[i] * (r - m);
    lazy[i << 1] += lazy[i];
    lazy[i << 1 | 1] += lazy[i];
    lazy[i] = 0;
}
void update1(int u, int v, int val, int id = 1, int l = 1, int r = n)
{
    if (l > r || r < u || v < l)
        return;
    if (u <= l && r <= v)
    {
        seg2[id] += val * (r - l + 1);
        lazy[id] += val;
        return;
    }
    pushdown1(id, l, r);
    int mid = l + r >> 1;
    update1(u, v, val, id << 1, l, mid);
    update1(u, v, val, id << 1 | 1, mid + 1, r);
    seg2[id] = seg2[id << 1] + seg2[id << 1 | 1];
}
int getsum1(int u, int v, int id = 1, int l = 1, int r = n)
{
    if (l > r || r < u || v < l)
        return 0;
    if (u <= l && r <= v)
        return seg2[id];
    pushdown1(id, l, r);
    int mid = l + r >> 1;
    return getsum1(u, v, id << 1, l, mid) + getsum1(u, v, id << 1 | 1, mid + 1, r);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("_ab.inp", "r"))
    {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    while (q--)
    {
        int x, l, r;
        cin >> x >> l >> r;

        if (x == 0)
        {
            update1(l, r, 1);
        }

        if (x == 1)
        {
            update1(l, r, -1);
        }

        if (x == 2)
        {
            update(l, r, 1);
        }

        if (x == 3)
        {
            update(l, r, -1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << get(i, i) + getsum1(i, i) << " ";
    }
}