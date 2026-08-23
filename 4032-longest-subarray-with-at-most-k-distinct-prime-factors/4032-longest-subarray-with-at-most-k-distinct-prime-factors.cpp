class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        

        auto get = [&](int x){
            vector<int> primes;
            for(int p = 2; (long long) p*p<=x; p++){
                if(x%p==0){
                    primes.push_back(p);
                    while(x%p==0) x/=p;
                }
            }
            if(x>1) primes.push_back(x);
            return primes;
        };
        unordered_map<int,int> freq;
        int left = 0, best = 0;
        for(int i=0;i<nums.size();i++){
            vector<int> rp = get(nums[i]);
            for(int p:rp)freq[p]++;
            while((int)freq.size()>k){
                vector<int>lp = get(nums[left]);
                for(int p: lp){
                    freq[p]--;
                    if(freq[p] == 0) freq.erase(p);
                }
                left++;
            }
            best = max(best,i-left+1);
        }

        return best;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna