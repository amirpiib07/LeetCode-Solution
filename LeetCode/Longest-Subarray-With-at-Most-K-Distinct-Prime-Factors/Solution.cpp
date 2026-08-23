1class Solution {
2public:
3    int longestSubarray(vector<int>& nums, int k) {
4        
5
6        auto get = [&](int x){
7            vector<int> primes;
8            for(int p = 2; (long long) p*p<=x; p++){
9                if(x%p==0){
10                    primes.push_back(p);
11                    while(x%p==0) x/=p;
12                }
13            }
14            if(x>1) primes.push_back(x);
15            return primes;
16        };
17        unordered_map<int,int> freq;
18        int left = 0, best = 0;
19        for(int i=0;i<nums.size();i++){
20            vector<int> rp = get(nums[i]);
21            for(int p:rp)freq[p]++;
22            while((int)freq.size()>k){
23                vector<int>lp = get(nums[left]);
24                for(int p: lp){
25                    freq[p]--;
26                    if(freq[p] == 0) freq.erase(p);
27                }
28                left++;
29            }
30            best = max(best,i-left+1);
31        }
32
33        return best;
34    }
35};