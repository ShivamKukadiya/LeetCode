class Solution {
public:
    int num = 0;
    void traversal(TreeNode* & root){
        if(root == NULL){
            return;
        }
        if(root->val == num && root->left == NULL && root->right == NULL){
            root = NULL;
            return;
        }
        
        if(root->left != NULL){
            if(root->left->val == num && root->left->right == NULL && root->left->left == NULL){
            root->left = NULL;
            return;
        }
        }
        if(root->right != NULL){
            if(root->right->val == num && root->right->left == NULL && root->right->right == NULL){
            root->right = NULL;
            return;
        }
        }
        traversal(root->left);
        traversal(root->right);
    }
    void preorder(TreeNode*root,int &count){
        if(root == NULL){
            return;
        }
        if(root->val == num){
            count++;
        }
        preorder(root->left,count);
        preorder(root->right,count);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int count = 0;
        num = target;
        preorder(root,count);
        while(count != 0){
            traversal(root);
            count--;
        }
        return root;
    }
};