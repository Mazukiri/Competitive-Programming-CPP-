#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
string s;
ll ans;

ll calc(string &currChar, string &currExp)
{
    ll first = 0, second = 1;

    for (int i = 0; i < currChar.size() - 1; i++)
    {
        if (currChar[i] == 'C')
            first += 12;
        if (currChar[i] == 'H')
            first += 1;
        if (currChar[i] == 'O')
            first += 16;
    }

    ans += first;

    first = 0;

    if (currChar.back() == 'C')
        first += 12;
    if (currChar.back() == 'H')
        first += 1;
    if (currChar.back() == 'O')
        first += 16;

    if (currExp.size() != 0)
        second = stoll(currExp);

    return first * second;
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

    cin >> s;

    string currChar = "";
    string currExp = "";

    ans = 0;

    int i = 0;

    while (i < s.size())
    {
        while (s[i] == 'C' || s[i] == 'H' || s[i] == 'O')
        {
            currChar += s[i];
            i++;
        }

        while (s[i] >= '0' && s[i] <= '9')
        {
            currExp += s[i];
            i++;
        }

        if (currChar.size() > 0)
        {
            ans += calc(currChar, currExp);
            currChar = s[i];
            currExp = "";
            i++;
        }
    }

    if (currChar.size() > 0)
        ans += calc(currChar, currExp);

    cout << ans;
}