class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
            s.insert(nums1[i]);
        }
        int use1=s.size();
        s.clear();
        for(int i=0;i<n2;i++){
            s.insert(nums2[i]);
        }
        int use2=s.size();
        s.clear();
        for(int i=0;i<n1;i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            s.insert(nums2[i]);
        }
        int use3=s.size();
        return min(use3,min(n1/2,use1)+min(n2/2,use2));
        
    }
};