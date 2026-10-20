class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1;
        while(i <= j) {
            int sum = (i == j) ? people[i] : people[i] + people[j];
            if(sum <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
            ans++;
        }
        return ans;
    }
};