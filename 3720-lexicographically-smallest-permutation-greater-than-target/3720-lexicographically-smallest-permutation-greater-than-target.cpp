class Solution {
    bool f(int idx, string target, vector<int>& m, string curr, string& ans, bool isGreater){
        if(idx == target.size()){
            if(isGreater) {
                ans = curr;
                return true;
            }
            return false;
        }

        for(char i = 'a'; i <= 'z'; i++){
            if(m[i - 'a'] == 0) continue;
            if(!isGreater && i < target[idx]) continue;

            curr.push_back(i);
            m[i - 'a']--;
            bool flag = isGreater || (i > target[idx]);

            if(f(idx+1, target, m, curr, ans, flag)) return true;

            curr.pop_back();
            m[i - 'a']++;
        }

        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> m(26,0);
        for(auto &ch : s) m[ch - 'a']++;
        string ans = "";
        f(0, target, m, "", ans, false);
        return ans;
    }
};