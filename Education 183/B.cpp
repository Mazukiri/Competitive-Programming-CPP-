#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;

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

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        int count0, count1, count2;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                count0++;
            if (s[i] == '1')
                count1++;
            if (s[i] == '2')
                count2++;
        }

        string ans = "";

        for (int i = 1; i <= n; i++)
            ans += "+";

        for (int i = 0; i < count0; i++)
            ans[i] = '-';
        for (int i = ans.size() - 1; i >= count1; i--)
            ans[i] = '-';

        int countFor = 1;
        int index = count0;

        while (countFor <= count2)
        {
            ans[index] = '?';
            ans[ans.size() - 1 - index] = '?';
            index++;
            countFor++;
        }

        cout << ans << '\n';
    }
}