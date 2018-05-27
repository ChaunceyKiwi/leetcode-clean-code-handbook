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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }

        int M = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[M]);
        vector<int> vec1;
        vector<int> vec2;

        for (int i = 0; i < M; i++) {
            vec1.push_back(nums[i]);
        }

        for (int i = M + 1; i < nums.size(); i++) {
            vec2.push_back(nums[i]);
        }

        root->left = sortedArrayToBST(vec1);
        root->right = sortedArrayToBST(vec2);
        return root;
    }
};
