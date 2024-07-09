class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int n  =nums.size()-1;

        nums.erase(unique(nums.begin(),nums.end()) , nums.end());
        if(nums.size() < 3){
            return nums.back();
        }
        return nums[nums.size()-3];
    }
};