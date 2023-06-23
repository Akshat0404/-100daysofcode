/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        int preStart = 0;
        return buildTreeHelper(preorder, inorder, inorderMap, preStart, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap, int& preStart, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIndex = inorderMap[rootVal];
        
        preStart++;
        
        root->left = buildTreeHelper(preorder, inorder, inorderMap, preStart, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderMap, preStart, inIndex + 1, inEnd);
        
        return root;
    }
};
