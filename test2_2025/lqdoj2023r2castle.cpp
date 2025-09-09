#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2005;
int n, m;
int a[MAX_N][MAX_N];
int l[MAX_N];
int r[MAX_N];
int k[MAX_N];
deque<int> s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CASTLE.inp", "r", stdin);
    freopen("CASTLE.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    long long answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == a[i - 1][j])
            {
                k[j]++;
            }
            else
            {
                k[j] = 1;
            }
        }
        while (!s.empty())
        {
            s.pop_back();
        }
        for (int j = 1, p = 0; j <= m; j++)
        {
            if (a[i][j] != a[i][j - 1])
            {
                while (!s.empty())
                {
                    s.pop_back();
                }
                p = j - 1;
                s.push_back(p);
            }
            while (s.back() > p && k[s.back()] >= k[j])
            {
                s.pop_back();
            }
            l[j] = s.back() + 1;
            s.push_back(j);
        }
        for (int j = m, p = m + 1; j > 0; j--)
        {
            if (a[i][j] != a[i][j + 1])
            {
                while (!s.empty())
                {
                    s.pop_back();
                }
                p = j + 1;
                s.push_back(p);
            }
            while (s.back() < p && k[s.back()] > k[j])
            {
                s.pop_back();
            }
            r[j] = s.back() - 1;
            s.push_back(j);
        }
        for (int j = 1; j <= m; j++)
        {
            answer += (r[j] - j + 1) * (j - l[j] + 1) * k[j];
        }
    }
    cout << answer;
    return 0;
}