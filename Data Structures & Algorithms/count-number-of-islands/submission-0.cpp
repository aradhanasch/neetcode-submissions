class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j])
            return;

        visited[i][j] = 1;
        dfs(i - 1, j, visited, grid, m, n);
        dfs(i + 1, j, visited, grid, m, n);
        dfs(i, j - 1, visited, grid, m, n);
        dfs(i, j + 1, visited, grid, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    dfs(i, j, visited, grid, m, n);
                }
            }
        }
        return cnt;
    }
};
