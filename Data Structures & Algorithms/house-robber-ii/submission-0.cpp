class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp, int end) {
        if(ind > end) 
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        
        int l = nums[ind] + f(ind + 2, nums, dp, end);
        int r = f(ind + 1, nums, dp, end);

        return dp[ind] = max(l, r);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n, -1);
        vector<int> ap(n, -1);
        return max(f(0, nums, dp, n - 2), f(1, nums, ap, n - 1));
    }
};
