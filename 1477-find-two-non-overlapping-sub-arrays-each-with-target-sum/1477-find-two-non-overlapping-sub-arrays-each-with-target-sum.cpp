class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        int bestLen = INT_MAX;
        int sum = 0;
        vector<int> bestIdx(n, INT_MAX);
        while(j < n){
            sum += arr[j];
            while(i < n && sum > target) sum -= arr[i++];

            if(sum == target){
                int len = j - i + 1;
                if(i > 0 && bestIdx[i - 1] != INT_MAX){
                    ans = min(ans, len + bestIdx[i - 1]);
                }
                bestLen = min(len, bestLen);
            }
            bestIdx[j] = bestLen;
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};