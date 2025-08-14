// #include <bits/stdc++.h>                                                                                                                                                                                      //Logm
// using namespace std;
// #define int long long
// const int N = 1e6 + 5, INF = 1e18;
// int n, q;
// int seg[4 * N];

// void update(int pos, int val, int id = 1, int l = 1, int r = n){

//     if (l == r) {
//         seg[id] = val; 
//         return;
//     }

//     int mid = (l+r)/2;

//     //push_down

//     if (pos <= mid) {   
    
//         update(pos, val, id*2, l, mid);    
//     }

//     else {
//         update(pos, val, id*2 + 1,  mid + 1, r);
//     }

//     //push_up

//     seg[id] = min(seg[2*id], seg[id*2 + 1]);
// }

// int get(int u, int v, int id = 1, int l = 1, int r = n){

//     if (u <= l && r <= v) return seg[id];
//     if (u > r || v < l) return INF;

//     int mid = (l+r)/2;
//     //push_down nếu có thì sẽ bỏ vào khúc này

    


//     return min(
//         get(u, v, id*2, l, mid),
//         get(u, v, id*2 + 1, mid + 1, r)
//     );
// }

// signed main() {
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     if (fopen("_ab.inp", "r")) {
//         freopen("_ab.inp", "r", stdin);
//         freopen("_ab.out", "w", stdout);
//     }

//     cin >> n >> q;

//     memset(seg , 0x3f, sizeof seg);

//     for (int i = 1; i<=n; i++){

//         int x; cin >> x; 
//         update(i, x);
//     }

//     // for (int i = 1; i<=n; i++) cout << seg[i] << " ";
//     // cout << '\n';

    

//     while (q--){
//         int l, r; cin >> l >> r;
        
//         cout << get(l, r) << '\n';
//     }
    
// }
#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int INF = 1e18;
int n, q;
int seg[4 * N];

void update(int pos, int val, int id = 1, int l = 1, int r = n){

    if (l == r){
        seg[id] = val;
        return;
    }

    int mid = l + r >> 1;

    if (pos <= mid) update(pos, val, id * 2, l, mid);
    else update(pos, val, id * 2 + 1, mid + 1, r);

    seg[id] = min(seg[id << 1 | 1], seg[id << 1]);
}

int get(int u, int v, int id = 1, int l = 1, int r = n){

    if (u > r || l > v) return INF;
    if (u <= l && r <= v) return seg[id];

    int mid = l + r >> 1;

    return min(get(u, v, id << 1, l, mid),
        get(u, v, id << 1 | 1, mid + 1, r));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i<=n; i++){
        int x; cin >> x;
        update(i, x);
    }

    while (q--){

        int l, r; cin >> l >> r;
        cout << get(l, r) << '\n';
    }
    
}