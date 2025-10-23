#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility> // Для std::pair

using namespace std;

int n;
vector<string> grid;

void solve()
{
    // Đọc input
    grid.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    // `frontier` lưu các tọa độ (hàng, cột) của những đường đi tốt nhất hiện tại
    // Ban đầu, chỉ có ô xuất phát (0, 0)
    vector<pair<int, int>> frontier;
    frontier.push_back({0, 0});

    // `result` là chuỗi kết quả, bắt đầu bằng ký tự ở ô (0, 0)
    string result = "";
    result += grid[0][0];

    // Chúng ta cần đi 2*n - 2 bước nữa để đến đích (tổng độ dài đường đi là 2*n - 1)
    for (int k = 1; k < 2 * n - 1; ++k)
    {
        char min_char = 'z' + 1; // Khởi tạo ký tự nhỏ nhất là một giá trị lớn
        vector<pair<int, int>> next_frontier_candidates;

        // 1. Từ các ô trong `frontier` hiện tại, tìm tất cả các ô tiếp theo có thể đi tới
        for (const auto &cell : frontier)
        {
            int r = cell.first;
            int c = cell.second;

            // Đi xuống
            if (r + 1 < n)
            {
                next_frontier_candidates.push_back({r + 1, c});
            }
            // Đi sang phải
            if (c + 1 < n)
            {
                next_frontier_candidates.push_back({r, c + 1});
            }
        }

        // Nếu không có đường đi nào nữa (đã đến đích), thoát vòng lặp
        if (next_frontier_candidates.empty())
        {
            break;
        }

        // 2. Tìm ký tự nhỏ nhất trong số các ô có thể đi tới
        for (const auto &cell : next_frontier_candidates)
        {
            min_char = min(min_char, grid[cell.first][cell.second]);
        }

        // 3. Nối ký tự nhỏ nhất vào kết quả
        result += min_char;

        // 4. Xây dựng `frontier` mới: chỉ bao gồm các ô có chứa ký tự `min_char`
        vector<pair<int, int>> next_frontier;
        for (const auto &cell : next_frontier_candidates)
        {
            if (grid[cell.first][cell.second] == min_char)
            {
                next_frontier.push_back(cell);
            }
        }

        // 5. Rất quan trọng: Loại bỏ các tọa độ trùng lặp trong `frontier` mới
        // Ví dụ: ô (2,2) có thể được đến từ (1,2) và (2,1). Ta chỉ cần lưu (2,2) một lần.
        sort(next_frontier.begin(), next_frontier.end());
        next_frontier.erase(unique(next_frontier.begin(), next_frontier.end()), next_frontier.end());

        // Cập nhật frontier cho bước tiếp theo
        frontier = next_frontier;
    }

    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n))
        return 0;

    solve();

    return 0;
}