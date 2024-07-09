class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        string arrow = "->";
        vector<string> v;
        int start = 0;
        int i;
        if(n == 0)
        {
            return v;
        }

        for(i=1;i<=n;i++)
        {
            if(i == n || nums[i] != nums[i - 1] + 1)
            {
                if(start == i - 1)
                {
                    v.push_back(to_string(nums[start]));
                }
                else
                {
                    v.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                }
                start = i;
            }
        }
        return v;
    }
};