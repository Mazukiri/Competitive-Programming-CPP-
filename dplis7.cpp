#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct để lưu cặp giá trị (A, B)
struct Pair {
    int A;
    int B;
};

// Hàm tìm dãy con tăng dài nhất
pair<int, vector<Pair>> longest_increasing_subsequence(vector<Pair>& pairs) {
    int n = pairs.size();
    vector<int> dp(n, 1);
    vector<int> previous(n, -1);
    
    // Sắp xếp các cặp (A, B) theo A tăng dần và nếu A bằng nhau thì B tăng dần
    sort(pairs.begin(), pairs.end(), [](const Pair& a, const Pair& b) {
        if (a.A == b.A) return a.B < b.B;
        return a.A < b.A;
    });

    // Tính toán mảng dp
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pairs[j].A < pairs[i].A && pairs[j].B < pairs[i].B && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                previous[i] = j;
            }
        }
    }

    // Tìm độ dài lớn nhất của dãy con
    int max_length = 0;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > max_length) {
            max_length = dp[i];
            index = i;
        }
    }

    // Truy ngược lại dãy con tăng dài nhất
    vector<Pair> lis;
    while (index != -1) {
        lis.push_back(pairs[index]);
        index = previous[index];
    }
    
    // Đảo ngược dãy con để có đúng thứ tự
    reverse(lis.begin(), lis.end());

    return {max_length, lis};
}

int main() {
    if (fopen("dp.inp", "r")) {
            freopen("dp.inp", "r", stdin);
            freopen("dp.out", "w", stdout);
        }
    
    int n;
    cin >> n;
    vector<Pair> pairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].A >> pairs[i].B;
    }

    auto result = longest_increasing_subsequence(pairs);
    int length = result.first;
    vector<Pair> sequence = result.second;

    cout << length << endl;
    for (const auto& p : sequence) {
        cout << p.A << " " << p.B << endl;
    }

    return 0;
}
