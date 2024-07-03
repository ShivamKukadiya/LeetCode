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
 #include<bits/stdc++.h>
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>vv;
        ok(root , "" , vv);
        return vv;
    }

    void ok(TreeNode* res , string path , vector<string>&s){
        if(res == nullptr)return;
        path += to_string(res->val);
        if(res->left == nullptr && res->right == nullptr){
            s.push_back(path);
        }else{
            ok(res->left , path + "->" , s);
            ok(res->right, path + "->" , s);
        }
    }
};