class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> m;
        m[0] = 1;
        int ans = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
             sum += nums[i];
            long long val = sum - k;
            if(m.find(val) != m.end()) {
                ans += m[val];
            }
            m[sum]++;
        }
        return ans;
    }
};