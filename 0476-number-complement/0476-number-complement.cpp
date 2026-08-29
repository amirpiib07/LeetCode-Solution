class Solution {
public:
    int findComplement(int num) {
        int ans = 0; 
        int idx = 31;
        for(int i = 31; i >= 0; i--){
            if((num & (1 << i))) {
                idx = i;
                break;
            }
        }
        for(int i = idx; i >= 0; i--){
            if(!(num & (1 << i))) ans += 1 << i;
        }

        return ans;
    }
};