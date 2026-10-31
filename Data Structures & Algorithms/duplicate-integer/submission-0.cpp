class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int val:nums){
            m[val]++;
            if(m[val]==2)   return true;
        }
        return false;
    }
};