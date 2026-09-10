class Solution {
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int &cnt, vector<int> &delRow, vector<int> &delCol) {
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()) {
            int s = q.size();
            cnt++;
            for(int k = 0; k < s; k++) {
                auto [r, c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        queue<pair<int, int>> q;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        bfs(q, grid, cnt, delRow, delCol);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return max(0, cnt - 1);
    }
};
