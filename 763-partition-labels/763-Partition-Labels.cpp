class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mpp(26, 0);

        
        for (char ch : s) {
            mpp[ch - 'a']++;
        }

        unordered_set<char> st;
        vector<int> ans;

        int count = 0;

        for (int idx = 0; idx < s.size(); idx++) {

            char ch = s[idx];

            
            st.insert(ch);

            
            mpp[ch - 'a']--;

            
            if (mpp[ch - 'a'] == 0) {
                st.erase(ch);
            }

            count++;

            
            if (st.empty()) {
                ans.push_back(count);
                count = 0;
            }
        }

        return ans;
    }
};