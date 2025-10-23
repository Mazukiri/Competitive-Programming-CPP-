#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
bool vis[N];
 
string check(string s)
{
    if (s == "1" || s == "10" || s == "01" || s == "0" || s == "00")
        return "YES";
 
    memset(vis, false, sizeof vis);
 
    for (int i = 0; i < s.size(); i++)
    {
        vis[i] = (s[i] == '0');
    }
 
    if (s[0] == '0')
        vis[1] = true;
    if (s[s.size() - 1] == '0')
        vis[s.size() - 2] = true;
 
    int left = 1, right = s.size() - 2;
 
    while (left <= right)
    {
        while (s[left] == '1' && left <= right)
            left++;
        while (s[right] == '1' && right >= left)
            right--;
 
        if (left == right && (vis[left + 1] || vis[left - 1]))
        {
            return "YES";
        }
 
        if (s[left] == '0')
        {
 
            if (vis[left + 1] == false)
            {
                vis[left + 1] = true;
                left += 2;
            }
 
            else
                return "YES";
        }
 
        if (s[right] == '0')
        {
 
            if (vis[right - 1] == false)
            {
                vis[right - 1] = true;
                right -= 2;
            }
 
            else
                return "YES";
        }
    }
 
    return "NO";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("_ab.inp", "r"))
    {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
 
    int t;
    cin >> t;
 
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << check(s) << '\n';
    }
}