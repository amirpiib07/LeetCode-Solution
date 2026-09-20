class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int idx = 0;
        for (auto& ch : s)
            sum += (27 - (ch - 'a' + 1)) * ++idx;
        return sum;
    }
};