class Solution {
public:
    int minInsertions(string s) {
        int d = 0, c = 0;
        for(char ch : s) {
            if(ch == '(') {
                c += 2;
                if((c & 1) == 1){
                    d++;
                    c--;
                }
            } else {
                c--;
                if(c < 0) {
                    d++;
                    c = 1;
                }
            }
        }
        return c + d;
    }
};