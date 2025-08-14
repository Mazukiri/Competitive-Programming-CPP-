#include <bits/stdc++.h>
using namespace std;

// Function to extract the maximum sum
int getMaxRookSum(vector<vector<int>>& board, int n) {
    vector<int> dp(1 << n, 0);
    
    // Iterate over each row of the board
    for (int row = 0; row < n; ++row) {
        vector<int> new_dp(1 << n, 0);
        
        // Iterate over all possible column bitmasks
        for (int mask = 0; mask < (1 << n); ++mask) {
            // Check each column in the current row
            for (int col = 0; col < n; ++col) {
                // If this column is not occupied in the current mask
                if (!(mask & (1 << col))) {
                    // Calculate new mask
                    int new_mask = mask | (1 << col);
                    // Update the new_dp for new_mask
                    new_dp[new_mask] = max(new_dp[new_mask], dp[mask] + board[row][col]);
                }
            }
        }
        
        // Update dp with new_dp for the next row
        dp = new_dp;
    }
    
    // The answer will be the maximum value in the dp array
    return *max_element(dp.begin(), dp.end());
}

int main() {
    
    if (fopen("SUMROOK.inp", "r")) {
            freopen("SUMROOK.inp", "r", stdin);
            freopen("SUMROOK.out", "w", stdout);
        }
    
    int t; cin >> t;

    for (int num = 1; num<=t; num++){

    
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    
    int result = getMaxRookSum(board, n);
    cout << "Case " << num << ": " << result << endl;
    
    }
    

}
