class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxi = 0;
        int res;
        sort(nums.begin(),nums.end());
        if(nums.size() <= 1){
            return 0;
        }

        for(int i = 1; i < nums.size(); i++){
           res = nums[i]-nums[i-1];
            maxi = max(res,maxi);
        }
        return maxi;
    }
};