/*2. Bài toán tìm bao lồi
Đề bài: Cho một tập điểm và tìm bao lồi của tập điểm đó. In ra các điểm nằm trên bao lồi.
Độ phức tạp: O(n logn), với n là số lượng cặp điểm của đầu vào.
Chứng minh chi tiết: https://www.geeksforgeeks.org/convex-hull-monotone-chain-algorithm/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define x first
#define y second

bool tright(II a, II b, II c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0; 
}
bool tleft(II a, II b, II c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0; 
}

const int N = 1e5+5;
int n;
II a[N];

void ConvexHull() {
    if (n == 1) return;
    sort(a, a + n);
    vector<II> up, down;
    II p1 = a[0], p2 = a[n-1];
    up.push_back(p1), down.push_back(p1);
    for (int i = 1; i < n; ++i) {
        if (i == n-1 || tright(p1, a[i], p2)) {
            while (up.size() >= 2 && !tright(up[up.size() - 2], up.back(), a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == n-1 || tleft(p1, a[i], p2)) {
            while (down.size() >= 2 && !tleft(down[down.size() - 2], down.back(), a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    n = 0;
    for (int i = 0; i < up.size(); ++i)
        a[n++] = up[i];
    for (int i = down.size() - 2; i > 0; --i)
        a[n++] = down[i];
}
int s(II a, II b, II c) {
    return abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}
signed main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].y >> a[i].x;

    //Tìm bao lồi
    ConvexHull();

    //In ra số điểm của bao lồi
    cout << n << '\n';

    

    //In ra tập điểm của bao lồi
    for (int i = 0; i < n; ++i)
        cout << a[i].y << ' ' << a[i].x << '\n';
    return 0;
}