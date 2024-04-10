class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if (root == nullptr) {
            return vv;
        }
        bool flag = true;
        queue<TreeNode*> qq;
        qq.push(root);
        while (!qq.empty()) {
            int n = qq.size();
            vector<int> v(n);
            for (int i = 0; i < n; i++) {
                TreeNode* p = qq.front();
                qq.pop();
                int inde = flag ? i : n - i - 1;
                v[inde] = p->val;
                if (p->left) {
                    qq.push(p->left);
                }
                if (p->right) {
                    qq.push(p->right);
                }
            }
            flag = !flag;
            vv.push_back(v);
        }
        return vv;
    }
};
