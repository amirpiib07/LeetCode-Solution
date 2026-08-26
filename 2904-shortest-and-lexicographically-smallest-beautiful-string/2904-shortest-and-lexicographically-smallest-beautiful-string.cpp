class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int len = INT_MAX;
        int i = 0, j = 0;
        int start = 0, end = 0;
        string ans = "";
        int c_one = 0;
        while(j < n){
            if(s[j] == '1') c_one++;
            // if(c_one == k + 1){
            //     while(c_one != k){
            //         if(s[i] == '1') c_one--;
            //         i++;
            //     }
            // }
            while(c_one == k && i< n){
                start = i;
                end = j;
                if(len > (j - i + 1)) {
                    len = (j - i + 1);
                    ans = s.substr(i,len);
                }
                if(len == (j - i + 1) && ans > s.substr(i,len)) {
                    ans = s.substr(i,len);
                }
                if(s[i] == '1') c_one--;
                i++;
            }

            j++;
        }


        return ans;
    }
};