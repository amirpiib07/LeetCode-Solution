class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int bestLen = INT_MAX;
        int bestStart = -1;
        int i = 0, c_one = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == '1') c_one++;

            
            while (c_one > k) {
                if (s[i] == '1') c_one--;
                i++;
            }

            
            while (c_one == k) {
                int curLen = j - i + 1;
                if (curLen < bestLen) {
                    bestLen = curLen;
                    bestStart = i;
                } else if (curLen == bestLen) {
                    
                    if (s.compare(i, bestLen, s, bestStart, bestLen) < 0) {
                        bestStart = i;
                    }
                }
                if (s[i] == '1') c_one--;
                i++;
            }
        }

        return bestStart == -1 ? "" : s.substr(bestStart, bestLen);
    }
};