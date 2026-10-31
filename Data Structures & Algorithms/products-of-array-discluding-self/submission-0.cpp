class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int pro=1;
            for(int j=0;j<n;j++){
                if(j!=i){
                    pro*=nums[j];
                }
            }
            ans[i]=pro;
        }
        return ans;
    }
};
