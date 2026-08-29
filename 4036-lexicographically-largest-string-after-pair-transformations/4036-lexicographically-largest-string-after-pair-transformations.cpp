class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;

        for (int n : nums) {
            string s = "";
            int i = 0;
            while (n > 0) {
                int r = n % 2;
                n = n / 2;
                if (r == 1) {
                    if (i >= 26)

                        s += string(1 << (i - 25), 'z');
                    else
                        s += (char)(i + 'a');
                }
                i++;
            }
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }
        return ans;
    }
};