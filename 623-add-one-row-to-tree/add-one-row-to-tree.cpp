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
void traversal(TreeNode* root,int val,int depth,int &curr_d, queue<TreeNode*> &q)
{
    while(!q.empty() && curr_d<depth)
    {
        if(curr_d==depth-1)
        {
            int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* curr=q.front();
           q.pop();
           TreeNode* nl=new TreeNode(val,curr->left,nullptr);
           TreeNode* rl=new TreeNode(val,nullptr,curr->right);
           curr->left=nl;
           curr->right=rl;
        }
        }
        else{
            int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        }
        
        curr_d++;
    }
    
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int curr_d=1;
        queue<TreeNode*> q;
        q.push(root);
        if(depth>1)
        traversal(root,val,depth,curr_d,q);
        else
        {
            TreeNode* nn=new TreeNode(val);
            nn->left=root;
            return nn;
        }
        return root;

        
    }
};