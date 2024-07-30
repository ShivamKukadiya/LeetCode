class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        priority_queue<int>qq;
        for (int i = 1; i < n; i++) {
            qq.push(nums[i]);
            if(qq.size() > 2){
                qq.pop();
            }
        }
        ans+=qq.top();
        qq.pop();
        ans+=qq.top();
        return ans;
    }
};