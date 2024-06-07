class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second; //to make the id starting from 0
            int first, last;
            long cur_id;
            
            for(int i=0; i<size; i++)
            {
                // for reindexing with 0 on each level
                cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                
                //storing first and last index for maximum width
                if(i==0) first = cur_id;
                if(i==size -1) last = cur_id;
                
                //traverse left and right of the node using 2*i+1 for left and 2*i+2 for right formula
                if(node->left) q.push({node->left, 2*cur_id+1});
                if(node->right) q.push({node->right, cur_id*2+2});
            }
            
            //finding max width
            ans = max(ans, last-first+1);
        }
        return ans;
        
    }
};