#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int realPos;
const int N = 2e5 + 5;
int segTree[4 * N];
int A[N];

void update(int pos, int value, int id = 1, int l = 1, int r = n) {
    
    if (l == r) {
        segTree[id] = value;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) update(pos, value, id * 2, l, mid);
    else update(pos, value, id * 2 + 1, mid + 1, r);

    segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
}

int get(int pos, int id = 1, int l = 1, int r = n) {

    if (l == r) {
        realPos = l;
        return 1;
    }

    int mid = l + r >> 1;

    if (segTree[id * 2] >= pos) {
        return get(pos, id * 2, l, mid);
    }
        
    return get(pos - segTree[id * 2], id * 2 + 1, mid + 1, r);
    
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    /*
    Tạo mảng giả 0-1 để get tổng sao cho = k
    Chặt nhị phân 
    Độ phức tạp cho get và update tổng sẽ là n * log^2(n)
    */

    cin >> n;

    for (int i = 1; i<=n; i++) {
        int x; cin >> x;
        update(i, 1);
        A[i] = x;
    }

    for (int i = 1; i<=n; i++) {
        int x; cin >> x;
        get(x);
        cout << A[realPos] << " ";
        update(realPos, 0);
    }
}