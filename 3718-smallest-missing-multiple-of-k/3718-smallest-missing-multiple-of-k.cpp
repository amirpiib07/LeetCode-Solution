class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(begin(nums), end(nums));
        int m = 1;
        while(true){
            if(st.count(k*m)){
                m++;
                continue;
            }
            return k*m;
        }
    }
};