struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = leftHeightOfTree(root);
        int rightHeight = rightHeightOfTree(root);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

private:
    int leftHeightOfTree(TreeNode* root) {
        int height = 0;
        while (root) {
            ++height;
            root = root->left;
        }
        return height;
    }

    int rightHeightOfTree(TreeNode* root) {
        int height = 0;
        while (root) {
            ++height;
            root = root->right;
        }
        return height;
    }
};
