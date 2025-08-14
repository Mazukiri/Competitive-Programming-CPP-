#include<bits/stdc++.h>
using namespace std;
#define ll long long

// I own this submission to Stefan Dascalescu, who has done a wonderful visualization + tutorial on this problem.
 
const ll mod = 1e9+7;
 

 
ll dp[1000002][2];
 
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    if (fopen("dp.inp", "r")) {
            freopen("dp.inp", "r", stdin);
            freopen("dp.out", "w", stdout);
    }
    
	
	// dp[i][0] = number of ways to add rectangles to the 2*i squares such that the last 2 squares are united
	// dp[i][1] = number of ways to add rectangles to the 2*i squares such that the last 2 squares are not united
	dp[1][0] = 1, dp[1][1] = 1;
	for(int i = 1; i < 1000000; ++i)
	{
		dp[i][0] %= mod;
		dp[i][1] %= mod;
		dp[i+1][0] += 2*dp[i][0];
		dp[i+1][1] += dp[i][0];
		dp[i+1][0] += dp[i][1];
		dp[i+1][1] += 4*dp[i][1];
	}
	int t;
	cin >> t;
	for(; t; --t)
	{
		int n;
		cin >> n;
		ll ans = (dp[n][0] + dp[n][1]);
        ans = ans % mod;
		cout << ans << '\n';
	}
	return 0;
}