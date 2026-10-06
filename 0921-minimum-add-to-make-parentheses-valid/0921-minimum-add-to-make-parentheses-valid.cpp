class Solution {
public:
    int minAddToMakeValid(string s) {
        int d = 0, o = 0;
        for(auto& ch : s) {
            if(ch == '(') o++;
            else {
                if(o != 0) o--;
                else d++;
            }
        }
        d += o;
        return d;
    }
};