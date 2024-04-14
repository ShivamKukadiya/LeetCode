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
    void oksum(TreeNode* root, int &ans) {
        if (root == nullptr)
            return;
        if (root->left != nullptr && root->left->left == NULL &&
            root->left->right == nullptr) {
            ans += root->left->val;
        }
        oksum(root->left, ans);
        oksum(root->right, ans);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // if(root == nullptr)return root->val;
        int ans = 0;
        oksum(root, ans);
        return ans;
    }
};