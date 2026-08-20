class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        int n = a.size();

        vector<int> a_one;
        vector<int> a_sec;

        a_one.push_back(a[0]);
        a_sec.push_back(a[1]);

        for (int idx = 2; idx < n; idx++) {
            if (a_one.back() > a_sec.back()) {
                a_one.push_back(a[idx]);
            } else {
                a_sec.push_back(a[idx]);
            }
        }

        for (int idx = 0; idx < a_sec.size(); idx++) {
            a_one.push_back(a_sec[idx]);
        }

        return a_one;
    }
};