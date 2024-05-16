/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* node) {
        if (node->left == NULL && node->right == NULL)
            return node->val;

        if (node->val == 2)
            return f(node->left) | f(node->right);
        else
            return f(node->left) & f(node->right);
    }
    bool evaluateTree(TreeNode* root) { return f(root); }
};