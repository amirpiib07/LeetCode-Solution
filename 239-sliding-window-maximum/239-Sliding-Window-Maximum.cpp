#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq; 
        std::vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            
            dq.push_back(i);

            
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};