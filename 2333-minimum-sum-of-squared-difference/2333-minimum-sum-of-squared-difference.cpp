
class Solution {
private:
    bool fun(auto& a, int m, long long k) {
        long long count = 0;
        int n = a.size();

        for (int idx = 0; idx < n; ++idx) {
            if (a[idx] > m) count += (a[idx] - m);
            if (count > k) return false;
        }

        return true;
    }

    int mx(auto& a) {
        int mxVal = 0;
        int n = a.size();

        for (int idx = 0; idx < n; ++idx)
            mxVal = max(mxVal, a[idx]);

        return mxVal;
    }

    int BS(auto& a, long long k) {
        int l = 0, h = mx(a);
        int ans = h;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (fun(a, m, k)) {
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }

public:
    long long minSumSquareDiff(vector<int>& a, vector<int>& b,
                               int k1, int k2) {
        int n = a.size();
        long long k = 1LL * k1 + k2;

        for (int idx = 0; idx < n; ++idx)
            a[idx] = abs(a[idx] - b[idx]);

        long long total = 0;
        for (int diff : a) total += diff;

        if (k >= total) return 0;

        int g = BS(a, k);
        long long used = 0;

        for (int idx = 0; idx < n; ++idx) {
            if (a[idx] > g) {
                used += a[idx] - g;
                a[idx] = g;
            }
        }

        
        long long rem = k - used;

        for (int idx = 0; idx < n && rem > 0; ++idx) {
            if (a[idx] == g && g > 0) {
                --a[idx];
                --rem;
            }
        }

        long long ans = 0;

        for (long long diff : a)
            ans += diff * diff;

        return ans;
    }
};
