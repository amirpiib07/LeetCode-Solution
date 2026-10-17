class Solution {
    int sum(int num) {
        int ans = 0;
        while(num > 0) {
            ans += (num % 10);
            num /= 10;
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int idx = 0, n = nums.size();
        for(int num : nums) mpp[num] = idx++;

        vector<int> sorted(nums);
        auto fun = [&] (int a, int b) {
            int x = sum(a), y = sum(b);
            if(x != y) {
                return x < y;
            }
            return a < b;
        };


        sort(begin(sorted), end(sorted), fun);
        

        int ans = 0;
        for(int idx = 0; idx < n; ++idx) {
            int val1 = nums[idx];
            int val2 = sorted[idx];

            if(val1 == val2) continue;

            int i = mpp[val2];
            nums[idx] = nums[i];
            nums[i] = val1;
            mpp[val2] = idx;
            mpp[val1] = i;
            ans++;
        }

        return ans;
    }
};