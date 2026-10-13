class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n = a.size();

        for (auto& num : a)
            if (num < 0) num = -num;

        sort(a.begin(), a.end(), greater<int>());

        n = (n & 1) == 0 ? n / 2 : n / 2 + 1;

        long long ans = 0;

        for (int idx = 0; idx < n; ++idx) {
            ans += 1LL * a[idx] * a[idx];

            if (idx + n < a.size()) {
                ans -= 1LL * a[idx + n] * a[idx + n];
            }
        }

        return ans;
    }
};