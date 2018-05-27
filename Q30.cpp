/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* node;

    TreeNode* sortedListToBST(int L, int R) {
        if (L > R) {
            return NULL;
        }

        int M = (L + R) / 2;
        TreeNode* leftTree = sortedListToBST(L, M - 1);
        TreeNode* root = new TreeNode(node->val);
        root->left = leftTree;
        node = node->next;
        root->right = sortedListToBST(M + 1, R);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        node = head;
        return sortedListToBST(0, len - 1);
    }
};
