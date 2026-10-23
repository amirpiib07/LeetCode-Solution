class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != i) {
                if(flag) {
                    ans = nums[i];
                    flag = false;
                    continue;
                }
                ans &= nums[i];
            }
        }
        return ans;
    }
};