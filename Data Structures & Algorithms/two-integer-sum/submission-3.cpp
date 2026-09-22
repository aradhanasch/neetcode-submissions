class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int req = target - val;
            if(m.find(req) != m.end()) {
                ans.push_back(m[req]);
                ans.push_back(i);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
