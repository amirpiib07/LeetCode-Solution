class Solution {
    bool f(int idx, string target, string curr,
           vector<int>& mpp, string& ans,
           int half, bool isGreater) {

        if (idx == half) {

            
            string second = curr;
            reverse(second.begin(), second.end());

            string candidate;

            
            if (target.size() & 1) {

                char mid = '#';

                for (int i = 0; i < 26; i++) {
                    if (mpp[i] == 1) {
                        mid = char('a' + i);
                        break;
                    }
                }

                candidate = curr + mid + second;
            }
            else {
                candidate = curr + second;
            }

            
            if (candidate > target) {
                ans = candidate;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            int c = ch - 'a';

            if (mpp[c] < 2)
                continue;

            if (!isGreater && ch < target[idx])
                continue;

            curr.push_back(ch);
            mpp[c] -= 2;

            bool flag = isGreater || (ch > target[idx]);

            if (f(idx + 1, target, curr,
                  mpp, ans, half, flag))
                return true;

            curr.pop_back();
            mpp[c] += 2;
        }

        return false;
    }

public:
    string lexPalindromicPermutation(string s, string target) {

        vector<int> mpp(26, 0);

        for (char ch : s)
            mpp[ch - 'a']++;

        int n = s.size();

        
        int odd = 0;

        for (int x : mpp)
            odd += (x & 1);

        if (odd > 1)
            return "";

        string ans = "";

        if (!f(0, target, "", mpp, ans,
               n / 2, false))
            return "";

        return ans;
    }
};