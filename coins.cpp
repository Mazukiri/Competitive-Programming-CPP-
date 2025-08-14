#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5; //constant 
//coins_needed[i]: số xu cần thiết để đánh tổ cái tổ thứ i;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    //i
    //A[i]
    //B[i]: i
    int n, m; cin >> n >> m;

    vector<II> coins(n);

    //coins[i].se: Nhập số xu mỗi con mang về tổ i
    for (int i = 0; i<n; i++) cin >> coins[i].se;
    
    //coins[i].fi: Số xu cần thiết để đánh đổ mỗi tổ
    //được tính bằng công thức: random_coins - coins[i].se

    for (int i = 0; i<n; i++) {
        int random_coins; cin >> random_coins;
        coins[i].fi = random_coins - coins[i].se;
    }

    sort(coins.begin(), coins.end());

    //Xem danh sách được sắp xếp ưu tiên số xu để đánh đổ 1 tổ
    // for (int i = 0; i<coins.size(); i++) {
    //     cout << coins[i].fi << " " << coins[i].se << '\n';
    // }

    for (int i = 0; i<n; i++){
        
        if (m >= coins[i].fi) {
            m += coins[i].se;
        }
    }

    cout << m << '\n';
       
}