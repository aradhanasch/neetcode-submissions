class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int val:nums){
            if(m.count(val))    return true;
            m[val]++;
        }
        return false;
    }
};