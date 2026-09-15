class Solution {
    vector<vector<bool>> palindrome;
    vector<int> dp;
    int fun(string& s, int n, int k){
        if(n < k) return 0;
        if(dp[n] != -1) return dp[n];
        int result = fun(s, n - 1, k);
        int j = n - 1;
        for(int i = 0; j - i + 1 >= k; i++){
            if(palindrome[i][j]){
                result = max(result, 1 + fun(s, i, k));
            }
        }

        return dp[n] = result;
    }
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1) return n;
        palindrome.assign(n + 1, vector<bool>(n + 1, false));
        dp.assign(n + 1, -1);
        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                int j = i + len - 1;
                if(i == j) palindrome[i][j] = true;
                else if(i + 1 == j) palindrome[i][j] = s[i] == s[j];
                else palindrome[i][j] = (s[i] == s[j]) && palindrome[i + 1][j - 1];
            }
        }

        return fun(s, n, k);
    }
};