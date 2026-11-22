class Solution {
public:
    bool checkString(string s) {
        
        bool b = true;
        
        for(char ch : s) {
            if(ch == 'b') {
                b = false;
            }
            if(!b and ch == 'a') return false;
        }
        
        return true;
    }
};