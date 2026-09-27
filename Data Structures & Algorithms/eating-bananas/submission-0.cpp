class Solution {
public:
    bool f(vector<int> &piles, int h, int mid) {
        int k = 0;
        for(int val : piles) {
            k += val / mid;
            if(val % mid != 0)
                k++;
        }
        return (k <= h);  
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int st = 1, end = mx;
        int ans = INT_MAX;
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(f(piles, h, mid)) {
                ans = min(ans, mid);
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};
