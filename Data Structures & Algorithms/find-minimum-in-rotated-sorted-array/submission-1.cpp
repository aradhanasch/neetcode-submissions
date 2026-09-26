class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(nums[st] <= nums[end])
                return nums[st];
            else if((mid != 0 && nums[mid - 1] >= nums[mid]) && (mid != n- 1 && nums[mid] <= nums[mid + 1])) 
                return nums[mid];
            else if(nums[st] <= nums[mid])
                st = mid  + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
