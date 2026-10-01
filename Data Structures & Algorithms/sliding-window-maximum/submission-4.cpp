class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        int i = 0, j = 0;
        vector<int> ans;
        while(j < n) {
            while(!q.empty() && nums[q.back()] < nums[j]) {
                q.pop_back();
            }
            q.push_back(j);
            if(j - i + 1 == k) {
                ans.push_back(nums[q.front()]);
                while(!q.empty() && q.front() <= i) {
                    q.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
