#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll A[N], dp[N];
int n;
vector<int> v;
ll segTree[4 * N];

void compress(vector<int> &a)
{
    set<int> s(a.begin(), a.end());
    vector<int> b(s.begin(), s.end());
    for (int &i : a)
        i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
}

void update(ll pos, ll val, int id = 1, int l = 0, int r = n - 1)
{
    if (l == r)
    {
        segTree[id] += val;
        return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
    {
        update(pos, val, id << 1, l, mid);
    }

    else
    {
        update(pos, val, id << 1 | 1, mid + 1, r);
    }

    segTree[id] = segTree[id << 1] + segTree[id << 1 | 1];
}

ll get(int u, int v, int id = 1, int l = 0, int r = n - 1)
{
    if (u > r || l > v)
    {
        return 0;
    }

    if (u <= l && r <= v)
    {
        return segTree[id];
    }

    int mid = (l + r) >> 1;

    return get(u, v, id << 1, l, mid) + get(u, v, id << 1 | 1, mid + 1, r);
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

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    compress(v);

    ll ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        ll currLength = get(1, v[i] - 1) + 1;
        currLength %= MOD;
        update(v[i], currLength);
        // cout << currLength << '\n';
        ans += currLength;
        ans %= MOD;
    }

    cout << ans;
}