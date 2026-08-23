class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        long long prev = (long long) lower - 1;
        for(int i = 0; i<=(int) nums.size(); i++){
            long long curr = (i==(int)nums.size())?(long long) upper+1:nums[i];
            if(curr-prev>=2){
                long long start = prev+1;
                long long end = curr-1;
                if(start<=upper){
                    result.push_back({(int)start, (int)min(end, (long long) upper)});
                }
            }
            prev = max(prev,curr);
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna