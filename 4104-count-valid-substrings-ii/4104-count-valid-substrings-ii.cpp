class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int left = 0;
        int a = -1, ab = -1;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'a') {
                a = i;
            } else if (ch == 'b') {
                if(a != -1) {
                    ab = a;
                }
            } else if (ch == 'c') {
                if(ab != -1) {
                    left = max(left, ab + 1);
                }
            }
            ans += i - left + 1;
        }
        return ans;
    }
};