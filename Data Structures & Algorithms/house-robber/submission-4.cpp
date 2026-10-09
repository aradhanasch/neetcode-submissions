class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp) {
        if(ind >= nums.size())
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int l = nums[ind] + f(ind + 2, nums, dp);//pick
        int r = f(ind + 1, nums, dp);//not pick

        return dp[ind] = max(l, r);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(0, nums, dp);
    }
};
