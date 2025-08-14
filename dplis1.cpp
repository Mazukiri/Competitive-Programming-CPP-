#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
#define int long long
int A[N], cnt[N]; //cnt[i] là số cách tạo ra dãy con tăng dài nhất kế thúc tại i, có độ dài dp[i]
int dp[N]; //dp[i] là tổng độ dài dãy con không giảm dài nhất kết thúc tại i
const long long BASE = 20071008;
//dp counting thuong o duoi dang to hop ==> Nen thuong phai mod voi BASE


signed main()
{

    //Tính chất quan trọng: 
    //số nhóm tăng ít nhất của mảng bằng độ dài dãy con không tăng dài nhất của mảng đó. 
    //Tương tự với số nhóm giảm ít nhất của mảng bằng độ dài dãy con không giảm dài nhất của mảng đó. 

if (fopen("dp.inp", "r")) {
        freopen("dp.inp", "r", stdin);
        freopen("dp.out", "w", stdout);
    }


    int n;
    cin >>n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    //khoi tao qhd
    for (int i = 1; i<=n; i++)
    {
        dp[i] = 1;
    }

    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<i; j++)
        {
            if (A[i] >= A[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    long long ans = 0;

   for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);

   cout << ans;




    return 0;
}
