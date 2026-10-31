class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>vec;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int val=target-nums[i];
            if(m.find(val)!=m.end()){
                vec.push_back(m[val]);
                vec.push_back(i);
                return vec;
            }
            m[nums[i]]=i;
        }
        return vec;
    }
};
