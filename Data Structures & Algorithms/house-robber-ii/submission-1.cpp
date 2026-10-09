class Solution {
public:
    int f(int st, vector<int> &nums, vector<int> &dp, int end) {
        for(int i = end; i >= st; i--) {
            dp[i] = max((dp[i + 2] + nums[i]), dp[i + 1]);
        }
        return dp[st];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        vector<int> ap(n + 3, 0);
        return max(f(0, nums, dp, n - 2), f(1, nums, ap, n - 1));
    }
};
