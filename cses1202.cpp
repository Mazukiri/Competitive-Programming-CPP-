#include <bits/stdc++.h>
using namespace std;
#define int long long
#define II pair<int,int>
#define fi first
#define se second
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

// Bài 1: Khớp xâu
vector<int> findPattern(string T, string P) {
    vector<int> res;
    int pos = T.find(P, 0);
    while (pos != string::npos) {
        res.push_back(pos);
        pos = T.find(P, pos + 1);
    }
    return res;
}

// Bài 2: Dãy nhị phân
vector<string> binaryStrings(int n) {
    vector<string> res;
    for (int i = 0; i < (1 << n); i++) {
        string s = bitset<20>(i).to_string().substr(20 - n);
        res.push_back(s);
    }
    return res;
}

// Bài 3: Đường đi mê cung (BFS)
vector<vector<int>> maze;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0;
}

int shortestPath(int n, II start, II end) {
    queue<pair<int, II>> q;
    q.push({0, start});
    while (!q.empty()) {
        auto [steps, u] = q.front(); q.pop();
        if (u == end) return steps;
        for (int i = 0; i < 4; i++) {
            int nx = u.fi + dx[i], ny = u.se + dy[i];
            if (isValid(nx, ny, n)) {
                maze[nx][ny] = 1;
                q.push({steps + 1, {nx, ny}});
            }
        }
    }
    return -1;
}

// Bài 4: N-Queen (Backtracking)
vector<int> queen;
int cnt = 0;

bool check(int row, int col) {
    for (int i = 0; i < row; i++)
        if (queen[i] == col || abs(queen[i] - col) == row - i)
            return false;
    return true;
}

void solveNQueen(int n, int row = 0) {
    if (row == n) { cnt++; return; }
    for (int col = 0; col < n; col++) {
        if (check(row, col)) {
            queen[row] = col;
            solveNQueen(n, row + 1);
        }
    }
}

// Bài 5: Mã đi tuần (Backtracking)
vector<vector<bool>> visited;
vector<II> knightMoves = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};

bool knightTour(int x, int y, int step, int n) {
    if (step == n * n) return true;
    for (auto [dx, dy] : knightMoves) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
            visited[nx][ny] = true;
            if (knightTour(nx, ny, step + 1, n)) return true;
            visited[nx][ny] = false;
        }
    }
    return false;
}

// Bài 6: Phân tích số
vector<vector<int>> factorize(int n, int i = 2) {
    if (n == 1) return {{}};
    vector<vector<int>> res;
    for (int j = i; j <= n; j++) {
        if (n % j == 0) {
            for (auto v : factorize(n / j, j)) {
                v.insert(v.begin(), j);
                res.push_back(v);
            }
        }
    }
    return res;
}

// Bài 7: Sudoku (Backtracking)
bool isSafeSudoku(vector<vector<int>>& board, int r, int c, int num) {
    for (int i = 0; i < 9; i++)
        if (board[r][i] == num || board[i][c] == num || board[r/3*3 + i/3][c/3*3 + i%3] == num)
            return false;
    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    for (int r = 0; r < 9; r++)
        for (int c = 0; c < 9; c++)
            if (board[r][c] == 0)
                for (int num = 1; num <= 9; num++)
                    if (isSafeSudoku(board, r, c, num)) {
                        board[r][c] = num;
                        if (solveSudoku(board)) return true;
                        board[r][c] = 0;
                    }
    return true;
}

// Bài 8: Leo bậc thang (DP)
int climbStairs(int n, int k) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k && i - j >= 0; j++)
            dp[i] += dp[i - j];
    return dp[n];
}

// Bài 9: Phân công công việc (Tham lam)
vector<vector<int>> cost;
vector<bool> assigned;
int n, minCost = INF;

void jobAssignment(int worker, int curCost) {
    if (worker == n) { 
        minCost = min(minCost, curCost);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!assigned[i]) {
            assigned[i] = true;
            jobAssignment(worker + 1, curCost + cost[worker][i]);
            assigned[i] = false;
        }
    }
}

// Bài 10: Người bán hàng (TSP - DP)
vector<vector<int>> dist;
bool visit[N];
int tspMinCost = INF;

void tspBruteForce(int city, int count, int curCost, int start) {
    if (count == n) {
        tspMinCost = min(tspMinCost, curCost + dist[city][start]);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            tspBruteForce(i, count + 1, curCost + dist[city][i], start);
            visit[i] = false;
        }
    }
}

// Bài 11: Cái túi (Quy hoạch động)
vector<int> w, v;
int M, maxValue = 0;

void knapsackBacktrack(int i, int curWeight, int curValue) {
    if (curWeight > M) return;
    maxValue = max(maxValue, curValue);
    if (i == w.size()) return;

    knapsackBacktrack(i + 1, curWeight, curValue); // Không chọn
    knapsackBacktrack(i + 1, curWeight + w[i], curValue + v[i]); // Chọn
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << "Done!";
}
