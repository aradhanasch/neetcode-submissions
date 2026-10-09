class Solution {
public:
    int f(int st, vector<int> &nums, int end) {
        int prev1 = 0, prev2 = 0;
        for(int i = end; i >= st; i--) {
            int curr = max((prev2 + nums[i]), prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        return max(f(0, nums, n - 2), f(1, nums, n - 1));
    }
};

