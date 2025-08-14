/*1. Bài toán tìm cặp điểm gần nhất
Đề bài, phân tích, chứng minh: https://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf
Code minh họa bên dưới được sử dụng theo ý tưởng chia để trị dựa vào slide trên.
Tuy nhiên, ta có thể sử dụng thuật toán Sweep-line để giải quyết bài toán này.
Độ phức tạp của thuật toán là O(nlogn), và dễ cài đặt hơn (ít nhất là với em :">")=
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const double INF = 1e20;

class Point {
public:
    double x, y;
    
    void inp() { cin >> x >> y; }

    bool operator<(const Point &other) const { return x < other.x; }
};

vector<Point> a(N), temp(N);
double mindist;

void upd_ans(const Point &p1, const Point &p2) {
    double dist = hypot(p1.x - p2.x, p1.y - p2.y);
    mindist = min(mindist, dist);
}

void find(int l, int r) {
    if (l >= r) return;
    
    if (r == l + 1) {
        upd_ans(a[l], a[r]);
        if (a[l].y > a[r].y) swap(a[l], a[r]);
        return;
    }

    int mid = (l + r) / 2;
    double midx = a[mid].x;
    find(l, mid);
    find(mid + 1, r);

    merge(a.begin() + l, a.begin() + mid + 1, a.begin() + mid + 1, a.begin() + r + 1, temp.begin(), 
          [](const Point &p1, const Point &p2) { return p1.y < p2.y; });

    copy(temp.begin(), temp.begin() + (r - l + 1), a.begin() + l);

    int tm = 0;
    for (int i = l; i <= r; i++) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tm - 1; j >= 0 && temp[j].y > a[i].y - mindist; j--) {
                upd_ans(a[i], temp[j]);
            }
            temp[tm++] = a[i];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }

    int n; cin >> n;
    for (int i = 0; i < n; i++) a[i].inp();

    mindist = INF;
    sort(a.begin(), a.begin() + n);
    find(0, n - 1);

    //In ra độ dài đường đi ngắn nhất
    cout << fixed << setprecision(6) << mindist;
}
