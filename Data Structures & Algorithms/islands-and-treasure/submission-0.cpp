class Solution {
public:
    void bfs(queue<tuple<int, int, int>> &q, vector<vector<int>> &grid, vector<int> &delRow, vector<int> &delCol) {
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = t + 1;
                    q.push({nr, nc, t + 1});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0)
                    q.push({i, j, 0});
            }
        }
        bfs(q, grid, delRow, delCol);
    }
};
