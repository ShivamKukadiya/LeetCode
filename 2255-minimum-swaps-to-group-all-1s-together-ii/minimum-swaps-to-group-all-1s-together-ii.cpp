class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;
        
        // Count the number of 1s in the original array
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                one++;
            }
        }
        
        // If there are no 1s, no swaps are needed
        if (one == 0) return 0;
        
        // Create a doubled array to simulate the circular array
        vector<int> vv(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            vv[i] = nums[i % n];
        }
        
        // Sliding window to find the max number of 1s in any window of size `one`
        int ans = 0;
        int current = 0;
        
        for (int i = 0; i < 2 * n; i++) {
            if (i >= one && vv[i - one] == 1) current--;
            if (vv[i] == 1) current++;
            ans = max(ans, current);
        }
        
        // The minimum number of swaps is the difference between total 1s and max 1s in a window
        return one - ans;
    }
};
