class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int val:nums){
            if(s.count(val))    return true;
            s.insert(val);
        }
        return false;
    }
};