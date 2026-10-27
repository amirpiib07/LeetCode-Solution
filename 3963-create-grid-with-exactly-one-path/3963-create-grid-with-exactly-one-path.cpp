class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s = "";
        for(int c = 0; c < n; ++c) {
            s += '.';
        }
        ans.push_back(s);
        for(int r = 1; r < m; ++r) {
            string t = "";
            for(int c = 0; c < n - 1; ++c) {
                t += '#';
            }
            t += '.';
            ans.push_back(t);
        }
        
        return ans;
    }
};