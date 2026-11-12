class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1, dec = 1, inc = 1;
        for(int idx = 1; idx < n; ++idx) {
            if (nums[idx] > nums[idx - 1]) {
                inc++;
                dec = 1;
            } else if (nums[idx] < nums[idx - 1]) {
                dec++;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            
            ans = max({ans, inc, dec});
        }
        
        return ans;
    }
};