class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        vector<int> num(10, 0);

        for (int d : digits)
            num[d]++;

        int ans = 0;

        for (int e = 0; e <= 8; e += 2) {

            if (num[e] == 0)
                continue;

            num[e]--;

            int distinct = 0;
            for (int d = 0; d <= 9; d++) {
                if (num[d] > 0)
                    distinct++;
            }

            for (int h = 1; h <= 9; h++) {

                if (num[h] == 0)
                    continue;

                ans += distinct - (num[h] == 1);
            }

            num[e]++;
        }

        return ans;
    }
};