class Solution {
public:
    bool isValidBST(TreeNode* root, int* low, int* high) {
        if (root == NULL) {
            return true;
        }

        if ((low != NULL && root->val <= *low) || (high != NULL && root->val >= *high)) {
            return false;
        }

        return isValidBST(root->left, low, &root->val) && isValidBST(root->right, &root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};

class Solution {
public:
    int* prev;

    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return isMonoIncreasing(root);
    }

    bool isMonoIncreasing(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        if (isMonoIncreasing(root->left) == false) {
            return false;
        }

        if (prev != NULL && root->val <= *prev) {
            return false;
        }

        prev = &root->val;

        if (isMonoIncreasing(root->right) == false) {
            return false;
        }

        return true;
    }
};
