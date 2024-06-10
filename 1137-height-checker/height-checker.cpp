#include<bits/stdc++.h>
class Solution {
public:
    int heightChecker(vector<int>& height) {
        int n = height.size();
        int cnt = 0;

        // Create a sorted copy of the height vector
        vector<int> sorted_height(height);
        sort(sorted_height.begin(), sorted_height.end());

        // Compare each element of the original and sorted vectors
        for (int i = 0; i < n; i++) {
            if (height[i] != sorted_height[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};