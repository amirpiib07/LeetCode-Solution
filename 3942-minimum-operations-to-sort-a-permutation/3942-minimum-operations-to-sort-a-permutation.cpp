class Solution {
public:
    int minOperations(vector<int>& nums) {
        int inc = 0, dec = 0;
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            inc += ((nums[i - 1] + 1) % n == nums[i]);
            dec += (nums[i - 1] == (nums[i] + 1) % n);
        }
        if(inc == n - 1 and nums[0] == 0) return 0;
        if(inc == n - 1) {
            int left = n - nums[0];
            int right = 1 + (nums.back() + 1) + 1;
            return min(left, right);
        }
        if(dec == n - 1) {
            int left = n - nums.back() + 1;
            int right = (nums[0] + 1) % n + 1;
            return min(left, right);
        }

        return -1;
    }
};