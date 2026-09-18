class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<int> isvalid(26, true);

        vector<string> ans;

        
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if (start[idx] == -1) {
                start[idx] = i;
            }

            end[idx] = i;
        }

        
        for (int c = 0; c < 26; c++) {

            if (start[c] == -1)
                continue;

            int l = start[c];
            int r = end[c];

            for (int i = l; i <= r; i++) {

                int idx = s[i] - 'a';

                
                if (start[idx] < l) {
                    isvalid[c] = false;
                    break;
                }

                
                r = max(r, end[idx]);
            }

            
            
            if (isvalid[c])
                end[c] = r;
        }

        int last = INT_MAX;

        
        for (int i = n - 1; i >= 0; i--) {

            int idx = s[i] - 'a';

            if (!isvalid[idx])
                continue;

            if (i == start[idx] && end[idx] < last) {

                ans.push_back(
                    s.substr(i, end[idx] - i + 1)
                );

                last = i;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};