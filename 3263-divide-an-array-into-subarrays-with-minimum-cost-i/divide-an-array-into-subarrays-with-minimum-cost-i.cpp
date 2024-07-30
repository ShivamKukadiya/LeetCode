class Solution 
{
public:
    int minimumCost(vector<int>& nums) 
    {
        int ans = nums[0];
        priority_queue<int> pq;
        for(int i=1 ; i<nums.size() ; i++)
        {
            pq.push(nums[i]);
            if(pq.size()>2)
                pq.pop();
        }
        ans += pq.top();
        pq.pop();
        ans += pq.top();
        return ans;
    }
};