#include <bits/stdc++.h>
using namespace std;

//Bài 1: Đếm số tổ hợp 
long long to_hop(int n, int k) {
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}

//Bài 2: Dãy con tăng dài nhất 
int lis(vector<int>& a) {
    int n = a.size();
    vector<int> f(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    return *max_element(f.begin(), f.end());
}

//Bài 3: Balo 0-1 
int knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w >= wt[i - 1]) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
}

//Bài 4: Xâu con chung dài nhất
int lcs(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

//Bài 5: Chọn cuộc họp 
int hop_nhieu_nhat(vector<pair<int, int>>& cuoc_hop) {
    sort(cuoc_hop.begin(), cuoc_hop.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int dem = 0, ket_thuc = -1;
    for (auto& [bat_dau, ket_thuc_hop] : cuoc_hop) {
        if (bat_dau >= ket_thuc) {
            dem++;
            ket_thuc = ket_thuc_hop;
        }
    }
    return dem;
}

//Bài 6: Cho thuê máy
int cho_thue_may(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = a.size();
    vector<tuple<int, int, int>> kh;
    for (int i = 0; i < n; i++) kh.emplace_back(b[i], a[i], c[i]);
    sort(kh.begin(), kh.end());
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        int lo = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (get<0>(kh[j]) <= get<1>(kh[i])) {
                lo = j;
                break;
            }
        }
        dp[i] = get<2>(kh[i]);
        if (lo != -1) dp[i] += dp[lo];
        if (i) dp[i] = max(dp[i], dp[i - 1]);
    }
    return dp[n - 1];
}

//Bài 7: Xếp khối đá 
int xep_khoi_da(vector<tuple<int, int, int>>& khoi) {
    vector<tuple<int, int, int>> list_all;
    for (auto [x, y, z] : khoi) {
        vector<int> dims = {x, y, z};
        sort(dims.begin(), dims.end());
        do {
            list_all.emplace_back(dims[0], dims[1], dims[2]);
            //Next_permutation để tự pick tổ hợp
        } while (next_permutation(dims.begin(), dims.end()));
    }
    sort(list_all.begin(), list_all.end());
    int n = list_all.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        auto [a1, b1, c1] = list_all[i];
        for (int j = 0; j < i; j++) {
            auto [a2, b2, c2] = list_all[j];
            if (a2 < a1 && b2 < b1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

//Bài 8: Farmer IOI 2004
//Phiên bản cài đặt tương tự có thể được tìm thấy trên VNOI: https://wiki.vnoi.info/algo/dp/basic-dynamic-programming-1.md
int cay_oliu(int N, int M, int Q, vector<int> A, vector<int> B) {
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0) continue;
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (A[i - 1] + B[j - 1] <= Q) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[N][M];
}

int main() {
    
    return 0;
}
