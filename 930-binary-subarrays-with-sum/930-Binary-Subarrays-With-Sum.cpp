class Solution {
    int f(vector<int> a, int goal) {
        if (goal < 0)
            return 0;
        int left = 0, right = 0;
        int sum = 0;
        int count = 0;
        while (right < a.size()) {
            sum += a[right];
            while (sum > goal) {
                sum -= a[left];
                left++;
            }
            if (sum <= goal) {
                count += (right - left + 1);
            }
            right++;
        }

        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        return f(a, goal) - f(a, goal - 1);
    }
};