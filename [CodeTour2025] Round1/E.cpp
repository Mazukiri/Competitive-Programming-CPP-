#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

void compress(vector<ll> &a)
{
    set<ll> s(a.begin(), a.end());
    vector<ll> b(s.begin(), s.end());
    for (ll &i : a)
        i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
}

struct Node
{
    ll val;
    int len;
};

Node seg[4 * N];
int n;
vector<ll> h(N), v(N);

Node combine(Node a, Node b)
{
    if (a.val > b.val)
        return a;
    if (b.val > a.val)
        return b;
    // tổng bằng nhau
    if (a.len > b.len)
        return a;
    return b;
}

void update(int id, int l, int r, int pos, Node val)
{
    if (l == r)
    {
        seg[id] = combine(seg[id], val);
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid)
        update(id << 1, l, mid, pos, val);
    else
        update(id << 1 | 1, mid + 1, r, pos, val);

    seg[id] = combine(seg[id << 1], seg[id << 1 | 1]);
}

Node get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return {0, 0};
    }

    if (u <= l && r <= v)
    {
        return seg[id];
    }

    int mid = l + r >> 1;
    return combine(get(id << 1, l, mid, u, v),
                   get(id << 1 | 1, mid + 1, r, u, v));
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

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    compress(h);

    ll currMax = 0;

    for (int i = 0; i < h.size(); i++)
        currMax = max(currMax, h[i]);

    Node ans = {0, 0};

    for (int i = 0; i < n; i++)
    {
        Node best = get(1, 1, currMax, 1, h[i] - 1);
        Node curr = {best.val + v[i], best.len + 1};
        update(1, 1, currMax, h[i], curr);
        ans = combine(ans, curr);
    }

    cout << ans.val << " " << ans.len;
}