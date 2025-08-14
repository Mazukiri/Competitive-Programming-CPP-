#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;

int seg[4 * N];
void update(int pos, int val, int id = 1, int l = 1, int r = n){

    if (l == r){
        seg[id] += val;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) update(pos, val, id << 1, l, mid);
    else update(pos, val, id << 1 | 1, mid + 1, r);

    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

int get(int val, int id = 1, int l = 1, int r = n){

    if (l == r) {
        return l; //Dùng max nhưng get vị trí
    }

    int mid = l + r >> 1;

    if (seg[id << 1] >= val) return get(val, id << 1, l, mid);
    
    else return get(val, id << 1  | 1, mid + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i<=n; i++){

        int x; cin >> x;
        update(i, x);
    }

    for (int i = 1; i<=m; i++){
        int x; cin >> x;
        
        int posAns = get(x);
        if (seg[1] < x) cout << 0 << '\n'; //Khong du cho thang x voi con to nhat 
        
        else {
            update(posAns, -x); //Cập nhật lại
            cout << posAns << '\n';
        }
        
    }
}