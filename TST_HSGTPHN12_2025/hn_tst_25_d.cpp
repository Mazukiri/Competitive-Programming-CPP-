#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
ll pre[N];
string s;
ll K;

bool isVowels(char c)
{
    return (c == 'a') || (c == 'i') || (c == 'u') || (c == 'e') || (c == 'o');
}

namespace sub1
{
    /* Iterate through every possibe consecutive substring
        For each, have a for loop to check whether it satisfies the condition.
        If so, another for-loop will be added to calculate the X - Y
        After that, we verify X - Y <= K
        If so, ans++
    */

    void solve()
    {
        ll res = 0;

        for (int l = 0; l < s.size(); l++)
        {
            for (int len = 2; l + len - 1 < s.size(); len++)
            {
                int r = l + len - 1;
                int id = l, id1 = l;

                while (id <= r && !isVowels(s[id]))
                    id++;
                while (id <= r && isVowels(s[id]))
                    id++;
                while (id1 <= r && isVowels(s[id1]))
                    id1++;
                while (id1 <= r && !isVowels(s[id1]))
                    id1++;

                ll X = 0, Y = 0;

                if (id == r + 1 || id1 == r + 1)
                {

                    for (int i = l; i <= r; i++)
                    {
                        if (isVowels(s[i]))
                            X += (0 + s[i]);
                        else
                            Y += (s[i] - 0);
                    }
                }

                if (X > 0 && Y > 0 && X - Y >= 0 && X - Y <= K)
                {
                    res++;
                }
            }
        }

        cout << res;
    }
}

namespace sub2
{

    void solve()
    {
        ll res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            bool flagConsonant = false, flagVowel = false;
            ll currSum = 0;

            if (isVowels(s[i]))
            {
                flagVowel = true;
                currSum = s[i];
            }
            else
            {
                flagConsonant = true;
                currSum = -s[i];
            }

            for (int j = i + 1; j < s.length(); j++)
            {

                if (isVowels(s[j]) && flagVowel && !isVowels(s[j - 1]))
                {
                    break;
                }

                if (!isVowels(s[j]) && flagConsonant && isVowels(s[j - 1]))
                {
                    break;
                }

                if (!isVowels(s[j]) && !flagConsonant)
                {
                    flagConsonant = true;
                }

                if (isVowels(s[j]) && !flagVowel)
                {
                    flagVowel = true;
                }

                if (isVowels(s[j]))
                {
                    currSum += s[j];
                }

                else
                {
                    currSum -= s[j];
                }

                if (flagConsonant && flagVowel)
                {
                    if (currSum <= K && currSum >= 0)
                    {
                        res++;
                    }
                }
            }
        }
        cout << res;
    }
}

namespace sub3
{
    void solve()
    {
        ll n = s.size();

        // prefix sum: nguyên âm +, phụ âm -
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + (isVowels(s[i]) ? s[i] : -s[i]);
        }

        ll res = 0;
        int l = 0;

        while (l < n)
        {
            bool startVowel = isVowels(s[l]);
            int r = l;

            // Giai đoạn 1: toàn nguyên âm hoặc toàn phụ âm đầu tiên
            while (r + 1 < n && isVowels(s[r + 1]) == startVowel)
                r++;

            // Giai đoạn 2: phần còn lại phải là khác loại, nhưng chỉ được phép 1 pha
            int mid = r + 1;
            while (mid < n && isVowels(s[mid]) != startVowel)
            {
                // [l..mid] là 2 pha hợp lệ (nếu tồn tại cả 2 loại)
                ll diff = pre[mid + 1] - pre[l];
                if (diff >= 0 && diff <= K)
                    res++;

                mid++;
            }

            // sang vị trí tiếp theo
            l++;
        }

        cout << res;
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

    cin >> s;
    cin >> K;

    sub3::solve();
}