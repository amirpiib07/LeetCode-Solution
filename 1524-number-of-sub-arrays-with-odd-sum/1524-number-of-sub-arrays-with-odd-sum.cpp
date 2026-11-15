class Solution {
    int mod = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int cumSum = 0, e = 1, o = 0;
        int ans = 0;
        for(int num : arr) {
            cumSum += num;
            if(cumSum & 1) {
                ans += e;
                o++;
            } else {
                ans += o;
                e++;
            }
            ans = ans % mod;
        }
        
        return ans;
    }
};