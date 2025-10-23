#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll n;
ll segTree[4 * N];
vector<int> A;

void update(ll pos, ll val, int id = 1, int l = 0, int r = n - 1)
{

    if (l == r)
    {
        segTree[id] = max(segTree[id], val);
        return;
    }
    int mid = (l + r) >> 1;

    if (pos <= mid)
    {
        update(pos, val, id << 1, l, mid);
    }

    if (pos > mid)
    {
        update(pos, val, id << 1 | 1, mid + 1, r);
    }

    segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
}

ll get(int u, int v, int id = 1, int l = 0, int r = n - 1)
{
    // Hoàn toàn ngoài đoạn
    if (v < l || r < u)
        return 0;

    // Hoàn toàn nằm trong đoạn cần truy vấn
    if (u <= l && r <= v)
        return segTree[id];

    int mid = (l + r) >> 1;
    return max(get(u, v, id << 1, l, mid), get(u, v, id << 1 | 1, mid + 1, r));
}

void compress(vector<int> &a)
{
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &i : a)
        i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
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

    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }

    compress(A);

    for (int i = 0; i < n; i++)
    {
        ll best = get(1, A[i] - 1);
        update(A[i], best + 1);
        ans = max(ans, best + 1);
        // cout << best << '\n';
    }

    cout << ans;
}