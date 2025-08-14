#include <bits/stdc++.h>
using namespace std;

int main()
{
    if (fopen("DONGNUOC.inp", "r")) {
            freopen("DONGNUOC.inp", "r", stdin);
            freopen("DONGNUOC.out", "w", stdout);
        }
    
    long long n; cin >> n;
    long long ans = 0;
    while(n != 0)
    {
        long long temp = n;
        if(n == 2 || n == 3)
        {
            ans++;
            cout << ans;
            return 0;
        }
        if(n > 3 && n <= 8)
        {
            ans += 2;
            cout << ans;
            return 0;
        }
        if(n == 9)
        {
            ans += 3;
            cout << ans;
            return 0;
        }
        if(n == 10)
        {
            ans += 2;
            cout << ans;
            return 0;
        }
        temp /= 5;
        n %= 5;
        if(n == 1)
        {
            ans += (temp + 1);
            cout << ans;
            return 0;
        }
        ans += temp;
    }

}