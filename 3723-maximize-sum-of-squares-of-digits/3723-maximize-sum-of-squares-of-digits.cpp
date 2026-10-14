class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";
        
        int _9 = sum / 9;
        int r_9 = sum % 9;
        
        string ans(_9, '9');
        
        if(r_9 > 0) ans.push_back(r_9 + '0');
        
        ans.append(num - ans.size(), '0');
        
        return ans;
    }
};