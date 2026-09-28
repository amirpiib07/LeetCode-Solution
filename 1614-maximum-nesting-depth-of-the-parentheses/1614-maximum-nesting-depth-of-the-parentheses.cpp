class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, curr = 0;
        int n = s.size();
        for(int idx = 0; idx < n; idx++){
            if(s[idx] == '(') {
                curr++;
                ans = max(ans, curr);
            }
            else if(s[idx] == ')') {
                curr--;
            }
        }
        
        return ans;
    }
};