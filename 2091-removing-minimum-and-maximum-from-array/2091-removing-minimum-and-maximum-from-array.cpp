class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        int mini = nums[0], maxi = nums[0], idx_max = 0, idx_min = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                idx_max = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                idx_min = i;
            }
        }

        return idx_max > idx_min
                   ? min({idx_min + 1 + n - idx_max, idx_max + 1, n - idx_min})
                   : min({idx_max + 1 + n - idx_min, idx_min + 1, n - idx_max});
    }
};