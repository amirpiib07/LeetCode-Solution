class Solution {
    void fun(int n, int l, int r, string s, vector<string>& ans) {
        if(s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if(l < n) fun(n, l + 1, r, s + "(", ans);
        if(r < l) fun(n, l, r + 1, s + ")", ans);
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fun(n, 0, 0, "", ans);
        return ans;
    }
};