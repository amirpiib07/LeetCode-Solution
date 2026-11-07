class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<tuple<int, int, int>> stk;
        int n = types.size();
        for(int i = 0; i < n; i++) {
            int type = types[i];
            int col = colors[i];
            if(!stk.empty()) {
                auto [t, c, cnt] = stk.top();
                if(type == t and col == c) {
                    stk.pop();
                    stk.push({t, c, cnt + 1});
                } else {
                    stk.push({type, col, 1});
                }
            } else {
                stk.push({type, col, 1});
            }
            
            auto [t, c, cnt] = stk.top();
            if(cnt == groupSize[t]) {
                stk.pop();
            }
        }

        return stk.empty();
    }
};