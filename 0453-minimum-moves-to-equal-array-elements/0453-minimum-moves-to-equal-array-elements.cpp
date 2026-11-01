class Solution {
public:
    int minMoves(vector<int>& a) {
        int mn = *min_element(a.begin(), a.end());

        int ans = 0;

        for (int x : a) {
            ans += x - mn;
        }

        return ans;
    }
};