#include <bits/stdc++.h>
using namespace std;
long long dp[1005][1005];
//dp[i][j]: do dai cua xau con chung dai nhat,  trong i ky tu dau cua xau S va j ky tu dau tien cua xau T


//Trace kiểu này cần phải lưu toàn bộ dp.
//Để giảm chiều, ta phải giảm chiều dp --> Sử dụng mảng trace trên dp đã giảm chiều
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
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 

            //Nếu dp[i][j] không lấy thêm vào, ta chỉ cần kiểm tra trong phần không gian dp trước đó
            //so sánh dp[i-1][j] vs dp[i][j-1]

        }
    }


    int i = s.size();
    int j = t.size();

    string ans = "";

    while (i>0 && j>0){ //Nếu đã duyệt hết một xâu --> K cần duyệt xâu còn lại 

    //Lưu ý: Nhớ trừ 1 tại index do lúc nãy đã dịch xâu lên
        if (s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--;
            j--;
        }

        else if (dp[i-1][j] > dp[i][j-1]){

            i--;
        }

        else j--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans;



}
