class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int ans;
        unordered_set<int>s;

        int n = nums1.size();
        int m = nums2.size();
    
        for (int i = 0; i < n; i++) {
            s.insert(nums1[i]);
        }
        int s1 = s.size();
        s.clear();

        for (int i = 0; i < m; i++) {
            s.insert(nums2[i]);
        }
        int s2 = s.size();
        s.clear();

        for (int i = 0; i < n; i++) {
            s.insert(nums1[i]);
        }

        for (int i = 0; i < m; i++) {
            s.insert(nums2[i]);
        }

        int s3 = s.size();
        s.clear();

         return min(s3, min(n / 2 , s1) + min(m / 2 , s2));
        // return ans;
    }
};