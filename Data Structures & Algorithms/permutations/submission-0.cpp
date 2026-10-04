class Solution {
public:
    void f(int ind, vector<vector<int>> &ans, vector<int> &nums) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++) {
            swap(nums[i], nums[ind]);
            f(ind + 1, ans, nums);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(0, ans, nums);
        return ans;
    }
};
