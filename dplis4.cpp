#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int A[N], cnt[N]; //cnt[i] là số cách tạo ra dãy con tăng dài nhất kế thúc tại i, có độ dài dp[i]
int dp[N]; //dp[i] là tổng độ dài dãy con tăng dài nhất kết thúc tại i
const long long BASE = 20071008;
//dp counting thuong o duoi dang to hop ==> Nen thuong phai mod voi BASE

signed main()
{

    

    int n;
    cin >>n;

    for (int i = 1; i<=n; i++) cin >> A[i];

    //khoi tao qhd
    for (int i = 1; i<=n; i++)
    {
        dp[i] = A[i];
    }

    //Length: Xem day con tang dai nhat co bao nhieu phan tu
    int length = 0;


    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<i; j++)
        {
            if (A[i] > A[j] && (gcd(A[i], A[j]) > 1)) dp[i] = max(dp[i], dp[j] + A[i]);
        }
    }

    long long ans = 0;

   for (int i = 1; i<=n; i++) ans = max(ans, dp[i]);

   cout << ans;




    return 0;
}
