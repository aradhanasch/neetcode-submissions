class Solution { //doing this using quick sort
public:
    int partition(vector<int> &nums, int low, int high) {
        int i = low;
        int j = high;
        int pivot = nums[low];
        while(i < j) {
            while(i < high && nums[i] <= pivot)
                i++;
            while(j > low && nums[j] > pivot)
                j--;
            if(i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        swap(nums[j],nums[low]);
        return j;
    }
    void quickSort(vector<int> &nums, int low, int high) {
        if(low < high) {
            int pInd = partition(nums, low, high);
            quickSort(nums, low, pInd - 1);
            quickSort(nums, pInd + 1, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }
};