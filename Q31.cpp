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
    int max_value;

    int findMax(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int max_temp = INT_MIN;
        int maxLeft = findMax(root->left);
        int maxRight = findMax(root->right);
        max_value = max(max_value, maxLeft + maxRight + root->val);
        max_temp = max(max_temp, maxLeft + root->val);
        max_temp = max(max_temp, maxRight + root->val);
        max_temp = max(max_temp, root->val);
        max_value = max(max_value, max_temp);

        return max_temp;
    }

    int maxPathSum(TreeNode* root) {
        max_value = INT_MIN;
        findMax(root);
        return max_value;
    }
};
