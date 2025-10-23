#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define double float
const int N = 5e5 + 5;
const double hx = (double)-0.5;
const double hy = (double)-sqrt(1 - 0.25);
const ll MOD = 1e9 + 7;
double X[N], Y[N];
long long ans[N];
bool isBlue[N];

double sqr(double x)
{
    return x * x;
}

double Euclid(double xA, double yA, double xB, double yB)
{
    return sqrt(sqr(yB - yA) + sqr(xB - xA));
}

bool isEquilateral(int i, int j, int l)
{
    double a = Euclid(X[i], Y[i], X[j], Y[j]);
    double b = Euclid(X[i], Y[i], X[l], Y[l]);
    double c = Euclid(X[l], Y[l], X[j], Y[j]);
    // cout << a << " " << b << " " << c << '\n';

    return (abs(a - b) < 1e-3 && abs(b - c) < 1e-3);
}

double solve(int n)
{
    int sz = n * (n + 1) / 2;
    double valx = 0, valy = 0;
    for (int i = 1, j = 1; j <= n; i += j, ++j)
    {
        X[i] = valx;
        Y[i] = valy;
        valx += hx;
        valy += hy;
    }

    for (int i = 2; i <= sz; ++i)
    {
        if (X[i] == 0)
        {
            X[i] = X[i - 1] + 1;
            Y[i] = Y[i - 1];
        }

        // cout << i << ' ' << X[i] << ' ' << Y[i] << '\n';
    }

    ll ans = 0;

    for (int i = 1; i <= sz - 2; i++)
    {
        if (isBlue[i])
            continue;
        for (int j = i + 1; j <= sz - 1; j++)
        {
            if (isBlue[j])
                continue;
            for (int l = j + 1; l <= sz; l++)
            {
                if (isBlue[l])
                    continue;
                if (isEquilateral(i, j, l))
                {
                    // double a = Euclid(X[i], Y[i], X[j], Y[j]);
                    // double b = Euclid(X[i], Y[i], X[l], Y[l]);
                    // double c = Euclid(X[l], Y[l], X[j], Y[j]);
                    // cout << a << " " << b << " " << c << '\n';
                    ans++;
                }
            }
        }
    }

    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("light.inp", "r"))
    {
        freopen("light.inp", "r", stdin);
        freopen("light.out", "w", stdout);
    }
    int n;
    cin >> n;

    int k;
    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        isBlue[x] = true;
    }

    if (n <= 100)
    {
        cout << solve(n) << '\n';
        return 0;
    }

    if (k == 0)
    {

        n += 2;
        cout << (n) * (n - 1) * (n - 2) * (n - 3) / 24;
    }
}