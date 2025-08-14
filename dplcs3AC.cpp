#include <bits/stdc++.h>
using namespace std;
long long dp[2][10005];
//dp[i][j]: do dai cua xau con chung dai nhat,  trong i ky tu dau cua xau S va j ky tu dau tien cua xau T
//Nhận xét: Ta thấy công thức chỉ cần tính dp[i-1][j], dp[i][j-1], dp[i-1][j-1]
//DP[0][1005]: Quy định trạng thái [0][j], [1][j]: chiều [0] tương đương với dp[i-1]; chiều [1] tương ứng với dp[i][j]
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    string s, t;
    
    cin >> s >> t;

    for (int i = 1; i<=s.size(); i++){
        for (int j = 1; j<=t.size(); j++){
            //Neu hai ky tu S[i] == T[j] thì lấy độ dài dài nhất của phần không gian trước đó trong dp
            //, chính là dp[i-1][j-1].
            if (s[i-1] == t[j-1]) dp[1][j] = dp[0][j-1] + 1;
            else dp[1][j] = max(dp[0][j], dp[1][j-1]); 
            
            //Nếu dp[i][j] không lấy thêm vào, ta chỉ cần kiểm tra trong phần không gian dp trước đó
            //so sánh dp[i-1][j] vs dp[i][j-1]
           
           
        }

        for (int j = 1; j<=t.size(); j++) {
            dp[0][j] = dp[1][j];
        }
        
    }

    cout << dp[1][t.size()];

    


    
}