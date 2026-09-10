class Solution {
    int ans = 0;

    pair<int, int> fun(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        
        pair<int, int> L = fun(root->left);
        pair<int, int> R = fun(root->right);

        int sum = root->val + L.first + R.first;
        int count = 1 + L.second + R.second;

        
        double avg = sum / count;

        if (round(avg) == root->val)
            ans++;

        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return ans;
    }
};