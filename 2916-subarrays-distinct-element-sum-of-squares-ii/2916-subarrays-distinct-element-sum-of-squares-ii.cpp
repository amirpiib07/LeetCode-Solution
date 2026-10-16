class Solution {
private:
    int n;
    int mod = 1e9 + 7;
    vector<long long> sumSegTree;
    vector<long long> sqSegTree;
    vector<long long> lazyTree;

    void add(int idx, int len, int val) {
        sqSegTree[idx] += 2LL * val * sumSegTree[idx] + 1LL * len * val * val;
        sumSegTree[idx] += 1LL * len * val;
        return;
    }

    void update(int start, int end, int idx, int l, int r, int val) {
        if(lazyTree[idx] != 0) {
            add(idx, r - l + 1, lazyTree[idx]);
            if(l != r) {
                lazyTree[2 * idx + 1] += lazyTree[idx];
                lazyTree[2 * idx + 2] += lazyTree[idx];
            }
            lazyTree[idx] = 0;
        }

        if(end < l || start > r || l > r) return;

        if(start <= l && r <= end) {
            add(idx, r - l + 1, val);
            if(l != r) {
                lazyTree[2 * idx + 1] += val;
                lazyTree[2 * idx + 2] += val;
            }
            return;
        }

        int mid = l + (r - l) / 2;

        update(start, end, 2 * idx + 1, l, mid, val);
        update(start, end, 2 * idx + 2, mid + 1, r, val);

        sumSegTree[idx] = sumSegTree[2 * idx + 1] + sumSegTree[2 * idx + 2];
        sqSegTree[idx] = sqSegTree[2 * idx + 1] + sqSegTree[2 * idx + 2];

        return;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sqSegTree.assign(4 * n, 0);
        sumSegTree.assign(4 * n, 0);
        lazyTree.assign(4 * n, 0);

        vector<int> lastSeen(100001, -1);
        int ans = 0;

        for(int idx = 0; idx < n; ++idx) {
            int start = lastSeen[nums[idx]] + 1;
            int end = idx;

            update(start, end, 0, 0, n - 1, 1);

            ans = (ans + sqSegTree[0]) % mod;
            lastSeen[nums[idx]] = idx;
        }

        return ans;
    }
};