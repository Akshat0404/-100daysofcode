class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;

        return root;
    }
};
