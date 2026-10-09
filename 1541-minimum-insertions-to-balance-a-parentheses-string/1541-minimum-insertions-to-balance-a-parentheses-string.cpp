class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int d = 0;
        stack<int> stk;
        bool check = false;
        for(char ch : s) {
            if(ch == '(') {
                if(check) {
                    ans += (d & 1) == 0 ? d / 2 : 2 + d / 2;
                    d = 0;
                    check = false;
                }
                // FIX: pichla '(' adhoora reh gaya, ek ')' insert karo
                if(!stk.empty() && stk.size() % 2 == 1) {
                    ans++;
                    stk.pop();
                }
                stk.push('(');
                stk.push('(');
            } else {
                if(stk.empty()) {
                    d++;
                    check = true;
                } else {
                    stk.pop();
                }
            }
        }
        if(check) {
            ans += (d & 1) == 0 ? d / 2 : 2 + d / 2;
        }
        return stk.size() + ans;
    }
};