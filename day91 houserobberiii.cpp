class Solution {
public:
    int rob(TreeNode* root) {
        auto result = robHelper(root);
        return std::max(result.first, result.second);
    }

private:
    std::pair<int, int> robHelper(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = robHelper(root->left);
        auto right = robHelper(root->right);

        int robCurrent = root->val + left.second + right.second;
        int skipCurrent = std::max(left.first, left.second) + std::max(right.first, right.second);

        return {robCurrent, skipCurrent};
    }
};
