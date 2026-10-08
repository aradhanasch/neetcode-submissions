class Solution {
public:
    int f(int n, vector<int> &cost, vector<int> &dp) {
        if(n >= cost.size())
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        int l = f(n + 1, cost, dp);
        int r = f(n + 2, cost, dp);

        return dp[n] = cost[n] + min(l, r);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(f(0, cost, dp), f(1, cost, dp));
    }
};
