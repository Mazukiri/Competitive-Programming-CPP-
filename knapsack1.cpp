#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
vector<int> value, weight;
ll DP[N]; //DP[W] = max(DP[totalWeight-weight[i]] + value[i], dp[W])
//DP[W] luu gia tri lon nhat tai can nang W
#dp
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }   

    int n, totalWeight; cin >> n >> totalWeight;

    for (int i = 0; i<n; i++) {
        int x, y; cin >> x >> y;
        weight.push_back(x);
        value.push_back(y);
    }


    for (int i = 0; i<n; i++) {

        //i: 1--> 3
        for (int w = totalWeight; w>=weight[i]; w--){
            //w: 11 --> 2
            //??? Cap nhat lai gia tri tot nhat co the lay, nhung khoi luong van dam bao la w
            //for (1-->n): mot tui se bi chon nhieu lan. De khac phuc loi nay, ta for (n-->1)
            //Khi cap nhat W, ta se lay trang thai W - weight[i] < W --> Trang thai nay chua duoc cap nhat (Không chứa túi thứ i).
            DP[w] = max(DP[w - weight[i]] + value[i], DP[w]);
            
        }
    }

    cout << DP[totalWeight];

    
    
}
