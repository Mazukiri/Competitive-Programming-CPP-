#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll dp[N][4]; 
ll A[N];
//DP[i][j] la so cach chon ra 1 bo gom j so trong i so dau tien
//DP[i][1] la so cach chon ra 1 bo gom 1 (=P) so trong i so dau tien
//DP[i][2] la so cach chon ra 1 bo gom 2 (=P va =Q, theo thu tu) so trong i so dau tien
//DP[i][3] la so cach chon ra 1 bo gom 3 (=P va =Q va =R, theo thu tu) so trong i so dau tien

//Note: De hieu ky hon thi co the in ra tung dp[i][1] --> dp[i][2] --> dp[i][3] bang 1 vong for

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("CHONTR.INP", "r")) {
        freopen("CHONTR.INP", "r", stdin);
        freopen("CHONTR.OUT", "w", stdout);
    }

    int n; cin >> n;

    for (int i = 1; i<=n; i++) cin >> A[i];
    
    int P, Q, R; cin >> P >> Q >> R;
    
    for (int i = 1; i<=n; i++){

        //Cap nhat ket qua cua cac bo chi so truoc do
        dp[i][1] += dp[i-1][1];
        dp[i][2] += dp[i-1][2];
        dp[i][3] += dp[i-1][3];
        
        //
        if (A[i] == P) dp[i][1]++; //Cap nhat so cach chon ra 1 bo gom 1 so trong i so dau tien
        if (A[i] == Q) dp[i][2] += dp[i-1][1]; //Cap nhat so cach chon ra 1 bo gom 2 so trong i so dau tien
        if (A[i] == R) dp[i][3] += dp[i-1][2]; ////Cap nhat so cach chon ra 1 bo gom 3 so trong i so dau tien
        
        //cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] <<  '\n';
    }

    cout << dp[n][3]; 


    
}