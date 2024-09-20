class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone = 0;       // To store the maximum count of consecutive ones
        int currentCount = 0; // To store the count of current consecutive ones
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currentCount++;          // Increase the count when we find a 1
                maxone = max(maxone, currentCount); // Update maxone if needed
            } else {
                currentCount = 0; // Reset current count when a 0 is encountered
            }
        }
        
        return maxone;
    }
};
