class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (!head || !head->next || !head->next->next)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int idx = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while (curr->next) {

            bool critical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (critical) {

                if (first == -1) {

                    first = idx;
                } else {

                    minDist = min(minDist, idx - last);

                    maxDist = idx - first;
                }

                last = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (maxDist == -1)
            return {-1, -1};

        return {minDist, maxDist};
    }
};