#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, maximumWeight;
int dp[N][N];
int backpack[N][N];
int weight[N], value[N];
//dp[n][w]: Giá trị lớn nhất có thể thấy khi có n đồ vật trong túi tại trọng lượng W

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> maximumWeight >> n;

    for (int i = 1; i<=n; i++) cin >> weight[i] >> value[i];

    //Đồ vật thứ i và cân nặng thứ w có giá trị lớn nhất ở thời điểm hiện tại
    //là dp[i][w]

    for (int i = 1; i<=n; i++){
        for (int w = 1; w<=maximumWeight; w++){

            if (weight[i] > w) {
                dp[i][w][] = dp[i-1][w];
                backpack[i][w] = backpack[i - 1][w];
            }
            else {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i]] + value[i]);

                if (dp[i][w] < dp[i-1][w - weight[i]] + value[i]) {
                    
                    dp[i][w] = dp[i-1][w - weight[i]] + value[i];
                    backpack[i][w] = i;

                }
            }
        }
    }

    cout << dp[n][maximumWeight] << '\n';



    
}