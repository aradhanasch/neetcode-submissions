class Solution {
public:
    int dfs(int r, int c, vector<vector<int>> &visited, vector<vector<int>> &grid, int m, int n) {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0 || visited[r][c])
            return 0;
        
        visited[r][c] = 1;

        return 1 + dfs(r - 1, c, visited, grid, m, n) + dfs(r + 1, c, visited, grid, m, n) + dfs(r, c - 1, visited, grid, m, n) + dfs(r, c + 1, visited, grid, m, n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int mx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    mx = max(mx, dfs(i, j, visited, grid, m, n));
                }
            }
        }
        return mx;
    }
};
