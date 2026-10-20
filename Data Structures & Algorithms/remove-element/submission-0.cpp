class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int v : nums) {
            if(v != val) 
                nums[k++] = v;
        }
        return k;
    }
};