class Solution {
public:
    string digitSum(string s, int k) {
       int n = s.size();
       if(n <= k) return s;
       
       string tmp = "";
       
       for(int idx = 0; idx < n; idx += k) {
           int val = 0;
           for(int j = idx; j < min(idx + k, n); j++) {
               val += (s[j] - '0');
           }
           tmp.append(to_string(val));
       }
       
       return digitSum(tmp, k);
    }
};