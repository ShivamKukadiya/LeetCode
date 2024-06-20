class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.back() - *nums.begin();
        for (int i = 0; i < nums.size() - 1; ++i){
            int smallest = min(nums[0] + k, nums[i + 1] - k);
            int biggest = max(nums[i] + k, nums.back() - k);
            ans = min(ans, biggest - smallest);
        }
        return ans;
    }
};