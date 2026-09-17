class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &heights, int prevHeight) {
        int m = heights.size();
        int n = heights[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || prevHeight > heights[i][j])
            return;

        visited[i][j] = 1;
        prevHeight = heights[i][j];

        dfs(i - 1, j, visited, heights, prevHeight);
        dfs(i, j + 1, visited, heights, prevHeight);
        dfs(i + 1, j, visited, heights, prevHeight);
        dfs(i, j - 1, visited, heights, prevHeight);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> visited1(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    if(!visited1[i][j]) {
                        dfs(i, j, visited1, heights, 0);
                    }
                }
            }
        }
        vector<vector<int>> visited2(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == m - 1 || j == n - 1) {
                    if(!visited2[i][j]) {
                        dfs(i, j, visited2, heights, 0);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited1[i][j] && visited2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
