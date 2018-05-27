/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return 1 + max(getDepth(root->left), getDepth(root->right));
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        int diffDepth = abs(leftDepth - rightDepth);

        return diffDepth <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
