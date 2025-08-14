#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 2e5 + 5;
int segTree[4 * N * 3];
int n, q;
vector<int> salary;
int A[N];
char types[N];
vector<II> Queries;

void update(int pos, int value, int id = 1, int l = 1, int r = N * 3) {

    if (l == r) {
        segTree[id] += value;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) update(pos, value, id * 2, l, mid);
    else update(pos, value, id * 2 + 1, mid + 1, r);

    segTree[id] = segTree[id *2] + segTree[id * 2 + 1];
}

int get(int u, int v, int id = 1, int l = 1, int r = 3 * N) {

    if (u <= l && r <= v)
        return segTree[id];

    if (u > r || l > v) 
    return 0;

    int mid = l + r >> 1;

    int lf = get(u, v, id << 1, l, mid);
    int rt = get(u, v, id << 1 | 1, mid + 1, r);

    return lf + rt;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    Queries.push_back(II(0, 0));
    
    cin >> n >> q;

    for (int i = 1; i<=n; i++) {
        cin >> A[i];
        salary.push_back(A[i]);
        //update(i, x);
    }
    
    for (int i = 1; i<=q; i++) {
        cin >> types[i];

        if (types[i] == '!') {
            int x, y; cin >> x >> y;
            salary.push_back(y);
            Queries.push_back(II(x, y));
        }

        if (types[i] == '?') {
            int x, y; cin >> x >> y;
            salary.push_back(x);
            salary.push_back(y);
            Queries.push_back(II(x, y));
        }
    }

    sort(salary.begin(), salary.end());
    salary.erase(unique(salary.begin(), salary.end()), salary.end());
    for (int i = 1; i <= n; ++i) {
        A[i] = lower_bound(salary.begin(), salary.end(), A[i]) - salary.begin() + 1;
    }

    for (int i = 1; i<=n; i++) {
        
        if (types[i] == '!') {
            int &y = Queries[i].se;
            y = lower_bound(salary.begin(), salary.end(), y) - salary.begin() + 1;
        }
        
        if (types[i] == '?') {
            int &x = Queries[i].fi;
            int &y = Queries[i].se;
            x = lower_bound(salary.begin(), salary.end(), x) - salary.begin() + 1;
            y = lower_bound(salary.begin(), salary.end(), y) - salary.begin() + 1;
        }
    }

    for (int i = 1; i<=n; i++) {
        update(A[i], 1);
        //equals to cnt[A[i]]++
    }

    for (int i = 1; i <=q; i++) {
        if (types[i] == '!')
        {
            update(A[Queries[i].fi], -1);
            update(Queries[i].se, 1);
            A[Queries[i].fi] = Queries[i].se;
        }

        if (types[i] == '?')
        {
            cout << get(Queries[i].fi, Queries[i].se) << '\n';
        }

        // for (int j = 1; j <= n; j++) cout << A[j] << " ";
        // cout << '\n';
        
        // for (int j = 1; j <= n; j++) cout << get(j, j) << " ";
        // cout << '\n'; 
    }
}