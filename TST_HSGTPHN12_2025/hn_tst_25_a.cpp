#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
string s;

bool check(int id)
{
    if (1 <= id + 1 && id + 1 <= 2)
    {
        return isupper(s[id]);
    }

    if (id + 1 == 3)
    {
        return s[id] == '-';
    }

    if (id + 1 >= 4 && id + 1 <= 6)
    {
        return (s[id] >= '0' && s[id] <= '9');
    }

    if (id + 1 == 7)
    {
        return s[id] == '.';
    }

    if (id + 1 >= 8 && id + 1 <= 9)
    {
        return (s[id] >= '0' && s[id] <= '9');
    }
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

    getline(cin, s);

    int ans = 0;

    for (int i = 0; i < 9; i++)
    {
        if (i < s.size() && !check(i))
        {
            ans = i + 1;
            break;
        }
    }
    {

        if (ans == 0 && s.size() < 9)
            ans = s.size() + 1;
    }

    if (ans == 0 && s.size() > 9)
        ans = 10;

    cout << ans;
}