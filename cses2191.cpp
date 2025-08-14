#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define x first
#define y second
const int N = 1e3 + 5;
int n;
II points[N];

int getArea(II a, II b, II c)
{
    return 1LL * ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i<=n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    II a = points[1];

    int area = 0;

    for (int i = 2; i<n; i++) {
        area += getArea(a, points[i + 1], points[i]);
    }

    cout << abs(area);
    

    
}