class Solution {
    vector<vector<int>> dp;
    int f(int i, int j, string s, string t){
        if(i == 0 && j > 0){
            return 0;
        }
        if(i == 0 && j == 0) return  1;
        if(j <= 0 && i > 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans1 = 0;
        int ans2 = 0;
        if(s[i - 1] == t[j - 1]){
            ans1 = f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);
        } else{
            ans2 = f(i - 1, j, s, t);
        }
        return dp[i][j] = ans1 + ans2;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        long long ans = f(n, m, s, t);
        return (int) ans;
    }
};