class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>v;
        ok(0,nums,res,v);
        return res;
    }

    void ok(int index,vector<int>&nums,vector<vector<int>>&res,vector<int>v){
        res.push_back(v);
        for(int i=index; i<nums.size(); i++){
            // if(i>index && nums[i-1]=nums[i])continue;
            v.push_back(nums[i]);
            ok(i+1,nums,res,v);
            int n=v.size();
            v.pop_back();
        }
    }
};