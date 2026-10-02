class Solution {
public:
    void f(int i, vector<int> &ds, vector<vector<int>> &ans, int target, vector<int> &nums) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        if(i == nums.size())
            return;

        if(nums[i] <= target) {
            ds.push_back(nums[i]);
            f(i, ds, ans, target - nums[i], nums);
            ds.pop_back();
        }    
        f(i + 1, ds, ans, target, nums);    
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, ds, ans, target, nums);
        return ans;
    }
};
