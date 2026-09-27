class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        
        stack<int> st;
        
        for(auto &ch : s){
            if(ch == '(') {
                st.push(ans.size());
            } else if(ch == ')') {
                int len = st.top();
                st.pop();
                reverse(begin(ans) + len, end(ans));
            } else {
                ans += ch;
            }
        }
        
        return ans;
    }
};