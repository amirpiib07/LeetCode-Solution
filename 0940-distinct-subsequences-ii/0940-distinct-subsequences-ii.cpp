class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9 + 7;

        int n = s.size();

        vector<long long> last(26, 0);

        for (int idx = 0; idx < n; idx++) {
            char ch = s[idx];
            int j = ch - 'a';
            long long sum = 0;

            for (int k = 0; k < 26; k++) {
                sum = (sum + last[k]) % mod;
            }

            last[j] = (sum + 1) % mod;
        }

        long long ans = 0;
        for (int num : last) {
            ans = (ans + num) % mod;
        }

        return (int)ans % mod;
    }
};