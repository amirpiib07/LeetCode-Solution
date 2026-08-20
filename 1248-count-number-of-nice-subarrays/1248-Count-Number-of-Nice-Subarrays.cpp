class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        set<int> s;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] & 1)
                s.insert(i);
        }

        int left = 0;
        int right = 0;
        int odd = 0;
        int count = 0;

        while (right < a.size()) {

            // Add current element
            if (a[right] & 1)
                odd++;

            // Remove elements from left until
            // window has at most k odd numbers
            while (odd > k) {
                if (a[left] & 1) {
                    odd--;
                    s.erase(s.begin());
                }
                left++;
            }

            // Exactly k odd numbers
            if (odd == k) {
                count += (*s.begin() - left + 1);
            }

            right++;
        }

        return count;
    }
};