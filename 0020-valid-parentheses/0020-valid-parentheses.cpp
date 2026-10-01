class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();
        for(int idx = 0; idx < n; idx++) {
            char ch = s[idx];
            if(stk.empty() || ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else {
                char m = stk.top();
                if(m == '{' && ch == '}') stk.pop();
                else if(m == '(' && ch == ')') stk.pop();
                else if(m == '[' && ch == ']') stk.pop();
                else return false;
            }
        }
        
        return stk.empty();
    }
};