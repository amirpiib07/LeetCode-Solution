class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> preSuff(n);
        preSuff[0].first = nums[0];
        preSuff[n - 1].second = nums[n - 1];

        for (int idx = 1; idx < n; idx++) {
            preSuff[idx].first = max(nums[idx], preSuff[idx - 1].first);
        }

        for (int idx = n - 2; idx >= 0; idx--) {
            preSuff[idx].second = min(nums[idx], preSuff[idx + 1].second);
        }

        int ans = -1;
        for (int idx = n - 1; idx >= 0; idx--) {
            if (abs(preSuff[idx].first - preSuff[idx].second) <= k)
                ans = idx;
        }

        return ans;
    }
};