class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int num = 0;
        unordered_map<int, int> eleGroup;
        unordered_map<int, list<int>> groupEle;
        eleGroup[vec[0]] = num;
        groupEle[0].push_back(vec[0]);

        for(int i = 1; i < n; i++){
            if(vec[i] - vec[i - 1] > limit) {
                num++;
            }
            eleGroup[vec[i]] = num;
            groupEle[num].push_back(vec[i]);
        }

        for(int i = 0; i < n; i++){
            int ele = nums[i];
            int lie_group = eleGroup[ele];
            int new_ele = *(groupEle[lie_group].begin());
            groupEle[lie_group].pop_front();
            nums[i] = new_ele;
        }

        return nums;
    }
};