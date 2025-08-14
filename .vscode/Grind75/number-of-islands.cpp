class Solution {
    private:
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        bool visited[305][305];
    
        bool isValid(int x, int y, int n, int m) {
            return x >= 0 && x <n && y >= 0 && y < m;
        }
    public:

        void DFS(int u, int v, vector<vector<char>> &grid) {
            
            visited[u][v] = true;

            for (int i = 0; i<4; i++) {
                int x = u + dx[i];
                int y = v + dy[i];

                if (isValid(x, y, grid.size(), grid[0].size()) 
                    && grid[x][y] == '1'   
                    && !visited[x][y]) {
                    DFS(x, y, grid);
                }
            }
        }

        int numIslands(vector<vector<char>>& grid) {
            
            int components = 0;
            
            for (int i = 0; i<grid.size(); i++) {
                for (int j = 0; j<grid[i].size(); j++) {
                    visited[i][j] = false;
                }
            }
             
            for (int i = 0; i<grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    
                    if (grid[i][j] == '1' && !visited[i][j]) {
                        DFS(i, j, grid);
                        components++;   
                    }
                }
            }

            return components;
        }
    };