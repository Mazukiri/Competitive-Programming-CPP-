    #include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e9;
int n;

// Kiểm tra xem mảng có sắp xếp tăng dần không
bool is_sorted(const vector<int> &x) {
    for (int i = 1; i < x.size(); ++i)
        if (x[i - 1] > x[i])
            return false;
    return true;
}

// DP lưu kết quả với trạng thái là mảng hiện tại
map<vector<int>, int> dp;

// Hàm quay lui + quy hoạch động
int backtrack(vector<int> a) {
    // Nếu mảng đã được sắp xếp -> không cần thao tác nữa
    if (is_sorted(a)) 
        return 1;

    // Nếu đã tính trạng thái này -> trả về luôn
    if (dp[a]) 
        return dp[a];

    int res = INF;

    // Thử tất cả các cặp (i, j), sort đoạn [i..j] và đệ quy tiếp
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> b = a;
            sort(b.begin() + i, b.begin() + j + 1);

            // Đệ quy cho mảng mới + chi phí là sqrt(j - i + 1)
            int cost = backtrack(b) + (int)sqrt(j - i + 1);

            res = min(res, cost);
        }
    }

    // Lưu kết quả
    dp[a] = res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // Đọc file nếu có
    if (fopen("_ab.inp", "r")) {
        freopen("_ab.inp", "r", stdin);
        freopen("_ab.out", "w", stdout);
    }
    if (fopen("SX.inp", "r")) {
        freopen("SX.inp", "r", stdin);
        freopen("SX.out", "w", stdout);
    }

    // Đọc dữ liệu
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    // Gọi hàm backtrack
    int ans = backtrack(a);

    // Do ban đầu bạn trả về ans - 1 nên mình giữ nguyên
    cout << ans - 1;

    return 0;
}
