class Solution {
public:
    void bfs(int i, int j, queue<pair<int, int>> &q, vector<vector<char>> &board, vector<vector<int>> &visited) {
        int m = board.size();
        int n = board[0].size();
        q.push({i, j});
        visited[i][j] = 1;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = r + delRow[k];
                int nc = c + delCol[k];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O' && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if(board[i][j] == 'O') {
                        bfs(i, j, q, board, visited);
                    }
                } 
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
