#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
const int N = 1e6 + 5;
int segTreeLeft[4 * N], segTreeRight[4 * N];
const int INF = 1e18 + 7;

void updateLeft(int pos, int value, int id = 1, int l = 1, int r = n){

    if (l == r) {
        segTreeLeft[id] = value;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) updateLeft(pos, value, id << 1, l, mid);
    else updateLeft(pos, value, id << 1 | 1, mid + 1, r);

    segTreeLeft[id] = min(segTreeLeft[id << 1], segTreeLeft[id << 1 | 1]);
}

int getLeft(int u, int v, int id = 1, int l = 1 , int r = n) {

    if (u <= l && r <= v) {
       return segTreeLeft[id]; 
    }

    if (u > r || l > v)
        return INF;

    int mid = l + r >> 1;

    int lf = getLeft(u, v, id << 1, l, mid);
    int rt = getLeft(u, v, id << 1 | 1, mid + 1, r);

    return min(lf, rt);
}

void updateRight(int pos, int value, int id = 1, int l = 1, int r = n) {
    
    if (l == r)
    {
        segTreeRight[id] = value;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid)
        updateRight(pos, value, id << 1, l, mid);
    else
        updateRight(pos, value, id << 1 | 1, mid + 1, r);

    segTreeRight[id] = min(segTreeRight[id << 1], segTreeRight[id << 1 | 1]);
}

int getRight(int u, int v, int id = 1, int l = 1, int r = n)
{

    if (u <= l && r <= v)
    {
        return segTreeRight[id];
    }

    if (u > r || l > v)
        return INF;

    int mid = l + r >> 1;

    int lf = getRight(u, v, id << 1, l, mid);
    int rt = getRight(u, v, id << 1 | 1, mid + 1, r);

    return min(lf, rt);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++) {    
        int x; cin >> x;
        updateLeft(i, x - i);
        updateRight(i, x + i);
    }

    // cout << getLeft(1, n) + 3<< " " << getRight(1, n) - 3 << '\n';

    for (int i = 1; i<=q; i++) {
        int typ; cin >> typ;

        if (typ == 1) {
            int x, pos; cin >> pos >> x;
            updateLeft(pos, x - pos);
            updateRight(pos, x + pos);
        }

        else {
            int k; cin >> k;

            if (k == 1) {
                int right = getRight(k, n) - k;
                cout << right << '\n';
                continue;
            }

            int left = getLeft(1, k) + k;
            int right = getRight(k + 1, n) - k;
            cout << min(left, right) << '\n'; 
        }

    }

    
    
}