class Solution {
private:
    int countValid(vector<int>& arr) {
        int m = arr.size();
        if (m < 2) return 0;

        vector<int> pre(m), suf(m);
        pre[0] = arr[0];
        for (int i = 1; i < m; i++) pre[i] = __gcd(pre[i - 1], arr[i]);

        suf[m - 1] = arr[m - 1];
        for (int i = m - 2; i >= 0; i--) suf[i] = __gcd(suf[i + 1], arr[i]);

        int cnt = 0;
        for (int i = 0; i < m - 1; i++) {
            if (pre[i] == suf[i + 1]) cnt++;
        }
        return cnt;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;

        int best = countValid(v);


        for (int k = 0; k < n; k++) {
            vector<int> arr;
            arr.reserve(n - 1);
            for (int i = 0; i < n; i++) {
                if (i != k) arr.push_back(nums[i]);
            }
            best = max(best, countValid(arr));
        }

        return best;
    }
};