class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int l = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i >= 2 and s[i - 2] == 'a' and s[i - 1] == 'b' and s[i] == 'c') {
                l = i - 1;
            }
            ans += i - l + 1;
        }
        return ans;
    }
};